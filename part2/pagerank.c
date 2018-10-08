#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){


    int **table1 = (int *) malloc(sizeof(int*) * 10);
    int **table2 = (int *) malloc(sizeof(int*) * 10);

    if (argc !=3){

        printf("Wrong number of arguments.\n");
        exit(EXIT_FAILURE);
    }


    char *filename1 = argv[1];
    char *filename2 = argv[2];

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen(filename1, "r");

    if(fp1 == NULL){

        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(filename2, "r");

    if(fp2 == NULL) {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    char tokens[4];
    tokens[0]= ' ';
    tokens[1] = '-';
    tokens[2] = '>';
    tokens[3] = ':';
    char line[20];
    char *tokenized;
    while (gets(line, 20, fp1) != NULL){

        tokenized = strtok(line, tokens);


    }



    return 0;
}