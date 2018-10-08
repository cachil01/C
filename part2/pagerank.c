#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){


    int **table1 = (int **) malloc(sizeof(int*) * 10);
    int **table2 = (int **) malloc(sizeof(int*) * 10);
	char **filedata = (char**) malloc(sizeof(char*) * 10);
	
	int p;
	for(p=0;p<10;p++){
		
			filedata[p] = (char*)malloc(sizeof(char) *30);
	}
	
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
    tokens[0] = ' ';
    tokens[1] = '-';
    tokens[2] = '>';
    tokens[3] = ':';
    char line[20];
	char *tokenized;
	int count = 0;
	char *point = *filedata;
    while (fgets(filedata[count], 50, fp1) != NULL){

        //tokenized = strtok(line, tokens);
		point++;
		count++;

    }

	printf("Number of lines: %d\n", count);
	int i;
	char* tempP = filedata;
	for (i =0; i< count ; i++){
		
			char*pointLine = *tempP;
			while(*pointLine != '\0'){
					printf("%c", *pointLine);
				
			}
			printf("\n");
			tempP++;
		
		
	}
	
	
	


    return 0;
}



