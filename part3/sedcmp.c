#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){



	if (argc!=3){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *filename1;
	char*filename2;

	filename1 = argv[1];
	filename2= argv[2];

	FILE *fp1 = fopen(filename1, "r");
	FILE *fp2 = fopen(filename2, "r");

	if(fp1 ==NULL || fp2 == NULL){
		printf("Failed to open file\n");
		exit(EXIT_FAILURE);
	}


	int size1;
	int size2;

	char *table1 = (char*) malloc(sizeof(char) * size1);
	char *table2 = (char * ) malloc(sizeof(char)*size2);

	char *dp1 = table1;
	char *dp2 = table2;

	if (table1 == NULL || table2 == NULL){
		printf("Failed to allocate memory. Exiting.\n");
		exit(EXIT_FAILURE);

	}
	
	int count1 = 0;
	int count2 =0;















}
