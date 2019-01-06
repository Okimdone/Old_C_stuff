#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//#include <string.h>

typedef uint8_t  BYTE;

// First 7bytes to check
typedef struct
    {
        BYTE check1;
        BYTE check2;
        BYTE check3;
        BYTE checke;
    }__attribute__((__packed__))
    FATsys;

int main(int argc,char *argv[])
{
    // the program shall not accept anything more than 1 arg
    if(argc != 2)
    {
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];
    // opening file for reading
    FILE *inptr = fopen(infile ,"r");

    // checking if the file exists
    if(inptr == NULL)
    {
        fprintf(stderr,"Unsupported file format!!\n");
        return 2;
    }

    // The number of FAT blocs to check
    fseek(inptr,0,SEEK_END);
    int blocks = ftell(inptr) / 512;
    rewind(inptr);

    // Allocation memory location for exchanging the possible Jpegs out
    char *MEM = malloc(512);

    // changing filename variable
    char filename[9] ;

    // looping on every block
    for(int i = 0,j = 0; i < blocks; i++)
    {
        // Check system for FAT blocks
        FATsys check;

        // typing the 1st 4 bytes info into check
        fread(&check , 4 , 1 ,inptr);

        // Checking for possible JPEGs
        if(check.check1 == 0xff && check.check2 == 0xd8 && check.check3 == 0xff && (check.checke == 0xe0 || check.checke == 0xe1 || check.checke == 0xe2 || check.checke == 0xe3 || check.checke == 0xe4 || check.checke == 0xe5 || check.checke == 0xe6 || check.checke == 0xe7 || check.checke == 0xe8 || check.checke == 0xe9 || check.checke == 0xea || check.checke == 0xeb || check.checke == 0xec || check.checke == 0xed || check.checke == 0xee ||check.checke == 0xef))
        {
            // Checking for error if j is bigger than the 3 char of the filename
            if(j > 999)
            {
                fprintf(stderr,"too many pictures to recover! max num is 1000 picture!\n");
                return 3;
            }

            // create the possible JPEG files
            sprintf(filename, "%.3i.jpg" , j);
            FILE *outptr = fopen(filename ,"w");

            // Check for error
            if(outptr == NULL)
            {
                fprintf(stderr,"couldn t create file num %.3i\n",j);
                return 4;
            }

            // next JPEG name num
            j++;

            // Copy the JPEG
            do
            {
            if(i >= blocks)
            {
                fclose(outptr);
                break;
            }
            //copy the first 7 bytes we checked
            fseek(inptr,- 4,SEEK_CUR);
            //fwrite(&check ,4 , 1 , outptr);

            //memcpy(outptr, inptr, 508);
            // Copy what s left from the block into the located memory
            fread(MEM , 512 , 1 , inptr);

            // Copy it back into the new possible JPEG file
            fwrite(MEM , 512 , 1 , outptr);

            // get the next check ready
            fread(&check, 4 ,1,inptr);

            if((check.check1 == 0xff && check.check2 == 0xd8 && check.check3 == 0xff && (check.checke == 0xe0 || check.checke == 0xe1 || check.checke == 0xe2 || check.checke == 0xe3 || check.checke == 0xe4 || check.checke == 0xe5 || check.checke == 0xe6 || check.checke == 0xe7 || check.checke == 0xe8 || check.checke == 0xe9 || check.checke == 0xea || check.checke == 0xeb || check.checke == 0xec || check.checke == 0xed || check.checke == 0xee ||check.checke == 0xef)) || (check.check1 == 0x00 && check.check2 == 0x00 && check.check3 == 0x00 && check.checke == 0x00))
            {
                // Ending the Jpeg s file
                i--;
                fclose(outptr);
                fseek(inptr,- 4,SEEK_CUR);
                break;
            }
            else
            {
                // go back the the start of the FAT block
                fseek(inptr,- 4,SEEK_CUR);

                // Copy what s left from the block into the located memory
                fread(MEM , 512 , 1 , inptr);

                // Copy it back into the new possible JPEG file
                fwrite(MEM , 512 , 1 , outptr);

                // get the next check ready
                fread(&check, 4 ,1,inptr);

                // Keep up with the blocks count
                i++;
            }


            }while(1);


            // block counts -1 , that would be added later by the loop itself
            i--;
        }
        else
        {
            fseek(inptr,508,SEEK_CUR);
        }
    }
    free(MEM);
    fclose(inptr);
    return 0;
}
