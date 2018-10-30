
#include <stdio.h>
#include <stdlib.h>
#include "run.h"

/*int isSolution(TREE_NODE *node, int size){
	
	int **temp = NULL;
	temp = node->puzzle;
	
		
	return 0;
	
}
*/

/*
	This method calculates the manhattan distance of the current puzzle to the solution. This distance	
	is less or equal to the amount of steps to reach the solution.


*/


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
	
	int **puzzle = (int**)malloc(sizeof(int*)*size);
	
	if(puzzle == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}


	printf("Break: 4\n");


	int **temp = NULL;
	int *temp2 = NULL;
	puzzle  = (int **) malloc(sizeof(int*)*size);
	
	if(puzzle == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}


	temp = puzzle;
	int i;
	
	printf("Break: 5\n");

	for(i=0;i<size;i++){
		*temp =(int*)malloc(sizeof(int)*size);
		
		if(temp == NULL){
			printf("Failed to allocate memory\n");
			exit(EXIT_FAILURE);
		}


		temp++; 

	}
	 

	temp = puzzle;
	printf("Break: 6\n");

	char *tmp = (char*) malloc(sizeof(char)*100);

	if(tmp == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}



	char *hp = NULL;
	while(fgets(tmp, 100, fp) != NULL){
		hp = tmp;
		temp2 = *temp;
		while(*hp!= '\0'){
			
			if(*hp != '\t' && *hp!= '\n' && *hp != '\0'){
			//if(*hp >= '0' && *hp <='9'){
				*temp2 = *hp - '0';

				temp2++;	
			}
			hp++;

		}

		temp++;		
	}

	
	
	return puzzle;
}