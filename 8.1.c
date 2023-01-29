#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    // check to see if destination file is enetered
    if (argc != 3) {
        // if no destination is provided show error message
        printf("Must supply a source and destination file\n");
        exit(1);
    }

    // open file for reading
    char line[255];
    FILE *in = fopen(argv[2], "r");

    // if cant open, show error message
    if (in == NULL) {
        printf("Cant open file for reading!\n");
        exit(1);
    }

    // get the line
    while (fgets(line, 255, in) != NULL) {

        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
        }
    }


} // end main
