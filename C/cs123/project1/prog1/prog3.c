#include<stdio.h>		//printf()
#include<stdlib.h>		//atoi()
#include<ctype.h>		//isdigit(), isalpha()
#include<string.h>		//strstr()
#include<pthread.h>

typedef struct args{
	const char* word,* inFile,* outFile;
	unsigned int p_index;
}ARGS_stc;

volatile unsigned int Traffic=0;

void createOutFile(char *outer);
void wait_access(unsigned int);
void give_access(void);
void out_file(const char* outFILE, const char *infile_name,unsigned int line_num,const char* line);
void* Handle_file(void* args);

int main(int argc, char** argv)
{
	//gdb
/*	argc = 6;
	char* C[]={"./pmatch","hello","2","h1.txt","h2.txt","out.txt"};
	argv = C;
*/

	/*First arguments verification
	*/
	int N;
	{
		if(argc < 5){
			exit_code:
			printf("Usage : ./pmatch [keyword] [N>=1] [input_file... * N] [output_file]\n");
			exit(1);
		}

		//testing N conditions (N is a num and N>=1)
		for(int i=0; argv[2][i] ; ++i)
		{
			if(!isdigit(argv[2][i])) goto exit_code;
		}
		N = atoi(argv[2]);
		if(N<1 || (argc - 4) != N)	goto exit_code;
	}

	//lists of prossesus children s id, and input files id
	pthread_t thread[N]; //FILE* f[N];
	//output files
	(void) createOutFile(argv[argc - 1]);

	ARGS_stc args[N];
	//generate thread children
	for(int i=0; i< N ; i++)
	{
		//attribute init
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		//thread calling
		printf("test for thread : %d\n",i);
		args[i].word=argv[1];	args[i].inFile =argv[3 + i];	args[i].outFile=argv[argc - 1]; args[i].p_index=i;
		printf("handling file index %d , %s\n........................\n",i,argv[3 + i]);
		if(pthread_create(thread+i , &attr, Handle_file, &args[i]) != 0)
		{
			perror("Couldn t create thread"); exit(EXIT_FAILURE);
		}
	}
	for(int i=0; i< N ; i++)
	{
		pthread_join(thread[i],NULL);
	}
	printf("Done\n");


}

void* Handle_file(void* args){
	ARGS_stc* args_cast = (ARGS_stc*) args;
	const char* word=args_cast->word,* inFile=args_cast->inFile,* outFile= args_cast->outFile;
	unsigned int i= args_cast->p_index;
	printf("handling file index %d id:%d, %s\n........................\n",i,(int)pthread_self(),inFile);
	//Child code
	FILE *f = fopen(inFile, "r");
	if(!f){
		perror("Error");exit(3);
	}

	char line[200];int line_num=0;
	//length of the searched string
	int len = strlen(word);
	while(!feof(f)){
		//read each line
		fscanf(f, "%[^\n]\n", line);line_num++;
		//find a match for argv[1] in the line
		char *ptr = strstr(line , word);
		//if it exists
		if(ptr){
			//if the char after the word is an alphabetical think about adding it
			if(!isalpha(ptr[len])){
				//if the word is not the first one, and has a letter before it , just go to the next line
				if(ptr!=line){
					if(isalpha(*(ptr - 1)))continue;
				}
				//wait for its turn, n write when the turn comes
				wait_access(i);
				//write the the out file
				out_file(outFile, inFile, line_num, line);
			}
		}
	}
	//give the turn for whoever child who needs it
	give_access();fclose(f);
	pthread_exit(0);
}


void createOutFile(char *outer){
	FILE* out = fopen(outer, "w");
	if(!out){
		perror("Error");exit(2);
	}
	//close the file
	fclose(out);
}

/*	the access to the output file would be automaticly
**	given to the first child created for the first file ,
**	n going all the way to the last one , while locking it for everyone else
*/
void wait_access(unsigned int p_index){
	// 0 for access | 1 for no access to the output file
	printf("wait_Access to %u, while Traffic : %d\n", p_index , Traffic);
	while(p_index != Traffic)
	continue;
}

/*	Give access for the next process(input file) to the output file
*/
void give_access(void){
    Traffic++;
}

void out_file(const char* outFILE, const char *infile_name,unsigned int line_num,const char* line){
	//open output file for writing
	FILE* out = fopen(outFILE, "a");
	if(!out){
		perror("Error");exit(2);
	}
	//pass the output matching line:
	fprintf(out, "%s, %d:%s\n", infile_name, line_num, line);
	//close the file
	fclose(out);
}