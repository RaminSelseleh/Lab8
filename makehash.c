#include <stdio.h>
#include "md5.h"
#include "string.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{

    if (argc != 3) {
        printf("Must supply a source and destination file\n");
        exit(1);
    }

    char line[255];
    FILE *in = fopen(argv[1], "r");

    if (in == NULL) {
        printf("Cant open file for reading!\n");
        exit(1);
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("cant open file for writting.\n");
        exit(1);
    }


    while (fgets(line, 255, in) != NULL) {

        char *nl = strchr(line, '\n');
        if (nl != NULL) *nl = '\0';

        char* hash = md5(line,strlen(line));
        printf("%s\n",hash);
        
        free(hash);
    }
    
    fclose(in);
    fclose(out);
}

