#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // making sure  0< n <= 100

    if(n <= 0 || 100 < n){
        fprintf(stderr,"n must be a positive number less than or equal to 100!\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int inpadding  =    (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding =    (4 - (bi.biWidth* n * sizeof(RGBTRIPLE)) % 4) % 4;

    // change outfile size in header

    bf.bfSize = bf.bfOffBits + (sizeof(RGBTRIPLE) * bi.biWidth* n + outpadding) * abs(bi.biHeight) * n;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    //change Width n height (xn) for the outimg

    int Width = bi.biWidth, Height = abs(bi.biHeight);
    bi.biWidth *= n;
    bi.biHeight *= n;

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0; i < Height; i++)
    {
        //copy every lane n times
        for(int h = 0; h < n ; h++)
        {

            // iterate over pixels in scanline
            for (int j = 0; j < Width; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //copy pixel n times

                for(int w = 0;w < n;w++){
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
           }

            // then add it back (to demonstrate how)
            for (int k = 0; k < outpadding; k++)
            {
                fputc(0x00, outptr);
            }

            //inptr------> 1st pixel of current line

            if(h < n-1)
            {
                fseek(inptr,- Width * 3, SEEK_CUR);
            }
            else
            {
                // skip over padding, if k = n - 1(last copied scan line)
                fseek(inptr, inpadding, SEEK_CUR);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
