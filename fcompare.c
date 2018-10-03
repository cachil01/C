#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  

int main (int argc, char *argv[]){

	if (argc != 1){

		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	


	char *filename1;
	char *filename2;
	filename1 = argv[2];
	filename2 = argv[3];
	
	compare(filename1, filename2);


    return 0;
}

void compare( char *filename1, char *filename2  ){
	
	FILE *fp = fopen(filename1, "r");	// Here the file is opened for reading
	FILE *fp2 = fopen(filename2, "r" );
	if(fp == NULL || fp2 == NULL ){
		printf("Failed to open file\n"); // Error message incase the file cant be opened
		exit(-1);
	}



	int flag =1;
	int count =0;
	char *temp;
	char *temp2;
	while (fgets(temp, 20, fp ) && fgets(temp2, 20, fp2)){


		if (strcmp(temp, temp2) != 0){

			flag =0;
			printf("The line %d is not equal\n", count);

			
		}
	
		count++;


	}
		
	printf("%d lines read\n", count);



	if(flag ==1){

		printf("the files are the same\n");
	}
	else{

		printf("the files are not the same\n");

	}
	





}


char makelc(char c){

	if (c>='A' && c<='Z'){

		return c + ('a' -'A');

	}

	return c;



}
