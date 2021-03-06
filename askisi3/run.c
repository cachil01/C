/**
* @file run.c
* @brief This is the source file for the functions that the main function requires for input output and algorithm calling.
*
* It contains a function that bast on the algorithm decided finds the solution. Also contains a funtion to find the size of the puzzle
* and a function to read the initial state of the puzzle from the input file.
*
* @author Christakis Achilleos
* @bug No known bugs. 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "run.h"




int runMethod(QUEUE *q, int size, char *fileout, int code){
	int i;
	while(q->size != 0){
			
			TREE_NODE *b =NULL;
			b = dequeue(q);
			
			
			for(i =0; i<4;i++){
				TREE_NODE *temp= NULL;
				
				temp = makeChild(b , i, size);
				if(temp != NULL){
					
					if(temp->h == 0){
							
							
						FILE *fp = NULL;
						fp = fopen(fileout, "w");
						if( fp == NULL){
							printf("FAILED TO OPEN FILE\n");
							exit(EXIT_FAILURE);
						}
						int count =0;
						
						printSolution(temp, &count, fp);
						fclose(fp);
						return 0;
					}
					else{
						
					
						switch (code){
						
							case 0:
							enqueue(q,temp);
							break;
							
							case 1:
							sortedEnqueue(q, temp);
							break;
							
							case 2:
							sortedEnqueue2(q, temp);
							break;
							
						}
						
						
					}
				}
			}
			
	}
	return 1;
	
	
}



int determineSize(char *filein){

	FILE *fp = NULL;
	fp = fopen(filein, "r");
	if(fp == NULL){
		printf("Error in opening file\n");
		exit(EXIT_FAILURE);
	}	
	
	int count=0;
	char *tmp =(char*) malloc(sizeof(char)*100);
	
	if(tmp == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	
	while(fgets(tmp, 100, fp) != NULL){
		count++;
	}
	free(tmp);

	return count;

}


int **readFile(char *filein, int size){

	FILE *fp = NULL;
	fp = fopen(filein, "r");

	if(fp == NULL){
		
		printf("Cannot open file\n");

		exit(EXIT_FAILURE);
	}


	int **temp = NULL;
	int *temp2 = NULL;
	int **puzzle  = (int **) malloc(sizeof(int*)*size);
	
	if(puzzle == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}


	temp = puzzle;
	int i;
	


	for(i=0;i<size;i++){
		*temp =(int*)malloc(sizeof(int)*size);
		
		if(temp == NULL){
			printf("Failed to allocate memory\n");
			exit(EXIT_FAILURE);
		}


		temp++; 

	}
	 

	temp = puzzle;


	char *tmp = (char*) malloc(sizeof(char)*100);

	if(tmp == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}




	while(fgets(tmp, 100, fp) != NULL){
		
		temp2 = *temp;
		
		
		char *token;
		char s[4] = "\t\n ";
		/* get the first token */
		token = strtok(tmp, s);
   
		/* walk through other tokens */
		while( token != NULL ) {
			*temp2 = atoi(token);
			temp2++;
			token = strtok(NULL, s);
		}

		
		temp++;		
	}

	
	
	return puzzle;
}