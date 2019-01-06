#include<stdio.h>		//printf()
#include<stdlib.h>		//atoi()
#include<sys/types.h>	//pid_t
#include<unistd.h>		//fork()
#include<ctype.h>		//isdigit(), isalpha()
#include<string.h>		//strstr()
#include <sys/wait.h>	//waitpid()

void createTrafficFile(void);
void createOutFile(char *outer);
void wait_access(int);
void give_access(int);
void out_file(char* out_file, char *infile_name,unsigned int line_num, char* line);

int main(int argc, char** argv)
{
	//gdb
	 argc = 6;
	char* C[]={"./pmatch","if","2","h1.txt","h2.txt","out.txt"};
	argv = C;

	//First arguments verification
	int N;
	{
		if(argc < 5){
			exit_code:
			printf("Usage : ./pmatch [keyword] [N>=1] [input_file... * N] [output_file]\n");
			exit(EXIT_FAILURE);
		}

		//testing N conditions (N is a num and N>=1)
		for(int i=0; argv[2][i] ; ++i)
		{
			if(!isdigit(argv[2][i])) goto exit_code;
		}
		N = atoi(argv[2]);
		if(N<1 || (argc - 4) != N)	goto exit_code;
	}

	//length of the searched string
	int len = strlen(argv[1]);

	//lists of prossesus children s id, and input files id
	pid_t pid[N]; FILE* f[N];
	//output file
	(void) createOutFile(argv[argc - 1]);
	//creates traffic.txt with "0" or "1" in it
	(void) createTrafficFile();

	//generate children and make em do their job
	for(int i=0; i< N ; i++)
	{
		if((pid[i]=fork()) < 0)
		{
			perror("Couldn t create child"); exit(2);
		}
		else if(pid[i] == 0)
		{//Child code
			f[i] = fopen(argv[3 + i], "r");
			if(!f[i]){
				perror("Error");exit(3);
			}

			char line[200];int line_num=0;
			while(!feof(f[i])){
				//read each line
				fscanf(f[i], "%[^\n]\n", line);line_num++;
				//find a match for argv[1] in the line
				char *ptr = strstr(line , argv[1]);
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
						out_file(argv[argc - 1], argv[3 + i], line_num, line);
					}
				}

			}
			//give the turn for whoever child who needs it
			give_access(i);fclose(f[i]);
			exit(0);
		}
	}/*
	for(int i=0; i< N ; i++)
	{
		waitpid(pid[i], NULL,0);
	}
	*/while(wait(NULL) > 0);// this > was a <
	printf("Done\n");


}

void createOutFile(char *outer){
	FILE* out = fopen(outer, "w");
	if(!out){
		perror("Error");exit(2);
	}
	//close the file
	fclose(out);
}
void createTrafficFile(void){
	//text file , for processus children to communicate
	FILE* traffic = fopen("traffic.txt", "w");
	if(!traffic){
		perror("Error");exit(3);
	}

	fprintf(traffic, "0");fclose(traffic);
}

/*	the access to the output file would be automaticly
**	given to the first child created for the first file ,
**	n going all the way to the last one , while locking it for everyone else
*/
void wait_access(int p_index){
	// 0 for access | 1 for no access to the output file
	int pass;
	//opening traffic file
	FILE* traffic = fopen("traffic.txt", "r+");
	if(!traffic){
		perror("Error");exit(3);
	}
	//scanf for permission
	do{
		fscanf(traffic,"%d", &pass);rewind(traffic);
	}while(pass != p_index);
	fclose(traffic);
}

/*	Give access for the next process(input file) to the output file
*/
void give_access(int p_index){
	FILE* traffic = fopen("traffic.txt", "w");
	if(!traffic){
		perror("Error");exit(3);
	}
	fprintf(traffic,"%ud", ++p_index);
	fclose(traffic);
}

void out_file(char* out_file, char *infile_name,unsigned int line_num, char* line){
	//open output file for writing
	FILE* out = fopen(out_file, "a");
	if(!out){
		perror("Error");exit(2);
	}
	//pass the output matching line:
	fprintf(out, "%s, %d:%s\n", infile_name, line_num, line);
	//close the file
	fclose(out);
}