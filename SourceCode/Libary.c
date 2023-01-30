#include "Header/Header.h"

const char *outputpath = "Output%d.txt";
const char *inputFile = "Input.txt";

FILE *output[9], *Input;

int count = 0;

char* lineRead(FILE * In, int strL)
{
    /* function to read input */
    char* inputStr = (char*)malloc(strL * sizeof(char));
    if (inputStr == NULL){
        printf("Something went wrong allocating the memory");
        exit(1);
    }
    int check;
    check = fscanf(In,"%s", inputStr);
    if (check == EOF){
        printf("Something went wrong reading the file");
        exit(1);
    }
    return inputStr;
}


int get_string_length(const char *filename) 
{
    /* function to get the length of the Text in the Input file */
    int length = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char Thischar;
    while ((Thischar = getc(fp)) != EOF) {
        length++;
    }
    fclose(fp);
    return length;
}

int count_delimiter(const char *filename, const char *delim) 
{
    int count = 0;
    char buffer[1024];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fgets(buffer, 1024, file) != NULL) {
        char *ptr = strstr(buffer, delim);
        while (ptr != NULL) {
            count++;
            ptr = strstr(ptr + strlen(delim), delim);
        }
    }

    fclose(file);
    return count;
}

void separateString(int amount, char *del, char *input)
{
    char *token = strtok(input, del);
    for (int i = 0; i < amount; i++){
        if (!token)
            break;
        fputs(token, output[i]);
        token = strtok(NULL, del);
    }
}

void openFiles(int amount)
{
    char filename[13], directory[16];
    for (int i = 0; i < amount; i++){
        sprintf(filename, outputpath, i + 1);
        strcpy(directory, "Output/");
        strcat(directory, filename);
        output[i] = fopen(directory, "w");
        if (!output[i]){
            printf("Failed generating file %s\n", directory);
            exit(1);
        }
    }
}

void closeFiles(int amount)
{
    for (int i = 0; i < amount; i++){
        if (fclose(output[i]) == EOF){
            printf("Failed closing file output%d.txt\n", i + 1);
            exit(1);
        }
    }
}

void errorHandeling(long int amount, const char *argv, const char *endptr)
{
    /* Checking for valid input */
if (errno == ERANGE && amount == LONG_MIN)
    {
        printf(" number : %lu  invalid  (underflow occurred)\n", amount);
        exit(1);
    }
    else if (errno == ERANGE && amount == LONG_MAX)
    {
        printf(" number : %lu  invalid  (overflow occurred)\n", amount);
        exit(1);
    }
    else if (errno == EINVAL)
    {
        printf(" number : %lu  invalid  (base contains unsupported value)\n", amount);
        exit(1);
    }
    else if (errno != 0 && amount == 0)
    {
        printf(" number : %lu  invalid  (unspecified error occurred)\n", amount);
        exit(1);
    }
    else if (errno == 0 && argv && *endptr != 0)
    {
        printf(" number : %lu    valid  (but additional characters remain)\n", amount);
    }
}
