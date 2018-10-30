
//#include "frontier_node.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int **readFile(char*filein, int size);
int determineSize(char *filein);


int main(int argc, char *argv[]){

	printf("Break: 1\n");
	if (argc != 4){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *filein = argv[2];
	//char *fileout = argv[3];
	printf("Break: 2\n");
	int size = determineSize(filein);
	//TREE_NODE *p = NULL;
	int **puzzle = readFile(filein, size);
	
	


	printf("Break: 7\n");


	
	printf("testing the readfile\n\n");
	
	int i,k;
	for(i = 0;i<size;i++){
		
		
		for(k =0;k<size;k++){
			printf("%d ",puzzle[i][k]);
			
		}
		printf("\n");
		
	}

	TREE_NODE *p = NULL;
	p= (TREE_NODE *) malloc(sizeof(TREE_NODE));
	
	printf("Break: 8\n");

	if(p == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	
	
	p->puzzle = puzzle;
	p->parent = NULL;

	QUEUE *q = NULL;
	q = initQueue(p);
	
	if(enqueue(q, p) != -1){
		
		

	}
	else{
		printf("Error, exiting\n");
		exit(EXIT_FAILURE);
	}	



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


int ** readFile(char *filein, int size){

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
				*temp2 = *hp - '0';

				temp2++;	
			}
			hp++;

		}

		temp++;		
	}

	
	
	return puzzle;
}








