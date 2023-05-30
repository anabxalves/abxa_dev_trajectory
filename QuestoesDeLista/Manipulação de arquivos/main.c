#include <stdio.h>
#include <stdlib.h>
#include "bmp_utils.h"

void greyScale(double size, BMPData *bmp_data);

int main(int argc, char* argv[]) 
{
    BMPData *bmp_data = NULL;
    BMPFileHeader file_header;
    BMPHeader bmp_header;

    // (QUESTÃO 1)
    bmp_data = bmp_read(argv[1], &file_header, &bmp_header);

    if (bmp_data == NULL)
    {
        printf("Unable to process file\n");
        exit(1);
    }

    // (QUESTÃO 2)
    double imgSize = (bmp_header.biWidth)*(bmp_header.biHeight);
    greyScale(imgSize, bmp_data);

    // (QUESTÃO 3)
    bmp_write(argv[2], &file_header, &bmp_header, bmp_data);

    // (QUESTÃO 4)
    free(bmp_data);

    return 0;
}

void greyScale(double size, BMPData *bmp_data)
{
    for(int i=0; i<size; i++)
    {
        int grey = ((bmp_data[i]).r) * 0.11 + ((bmp_data[i]).g)*0.59 + ((bmp_data[i]).b)*0.3;

        bmp_data[i].r = grey;
        bmp_data[i].g = grey;
        bmp_data[i].b = grey;
    } 
}