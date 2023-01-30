#include "Header/Header.h"

int main(int argc, char *argv[])
{
    (void)argc;
    char *endptr, *endptr2;
    //long int amount = strtol(argv[1], &endptr, 10); (needed for errorHandeling)
    int strLength = get_string_length(inputFile);
    char *inputString;
    char *delim = "|";

    Input = fopen(inputFile,"r");
    if (Input == NULL) {
        printf("Failed opening %s", inputFile);
        exit(1);
    }

    int count = count_delimiter(inputFile, delim);
    printf("%d", count);

    /* test to check if the user input was right (only used if parsing arguments with the .exe) */
    //errorHandeling(count, endptr);

    /* reading input File */
    inputString = lineRead(Input, strLength);

    /* opening Files */
    openFiles(count + 1);

    /* separating the String */
    separateString(count + 1, delim, inputString);

    /* closing Files */
    closeFiles(count + 1);

    free(inputString);
}
