
//#include "frontier_node.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue.h"
#include "run.h"
#include "tree_node.h"


int main(int argc, char *argv[]){

	printf("Break: 1\n");
	if (argc != 4){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	char *method = argv[1];
	char *filein = argv[2];
	char *fileout = argv[3];
	printf("Break: 2\n");
	int size = determineSize(filein);
	//TREE_NODE *p = NULL;
	int **puzzle = readFile(filein, size);
	
	


	printf("Break: 7\n");

	int h= 0;
	
	printf("testing the readfile\n\n");
	
	int i,k;
	
	for(i = 0;i<size;i++){
		
		
		for(k =0;k<size;k++){
			printf("%d ",puzzle[i][k]);
			
		}
		printf("\n");
		
	}

	TREE_NODE *p = NULL;
	initTreeNode(&p, puzzle, 0, h, NULL, 0);
	
	if( manhattan(p->puzzle,size) == 0){
			
		printf("The root is the solution\n");
		exit(EXIT_SUCCESS);							// checks root
			
	}
	
	QUEUE *q = NULL;
	q = initQueue(p);
	
	if(enqueue(q, p) == -1){
		
		
		printf("Error enquing, exiting\n");
		exit(EXIT_FAILURE);
		
	}

	
	//printing for first enqueue
	printf("first enqueue\n");
	for(i = 0;i<size;i++){
		
		
			for(k =0;k<size;k++){
				printf("%d ",q->frontier_tail->leaf->puzzle[i][k]);
			
			}
		printf("\n");
		
		
		
	}
	printf("--------------------------\n");
	
	if(strcmp(method, "breadth") == 0){
		int res =runMethod(q, size, fileout, 0);
		if(res == 1){
			printf("The solution was not found\n");
			return 0;
		}
	}
	else if(strcmp(method, "best") == 0){
		int res = runMethod(q, size, fileout, 1);
		if(res == 1){
			printf("The solution was not found\n");
			return 0;
		}
	}
	else if(strcmp(method, "a-star") == 0){
		int res = runMethod(q, size, fileout, 2);
		if(res == 1){
			printf("The solution was not found\n");
			return 0;
		}
	}
	else{
		printf("Wrong command argument!\n");
	}

	return 0;

}










