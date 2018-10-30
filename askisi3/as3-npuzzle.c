
//#include "frontier_node.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue.h"
#include "run.h"
#include "tree_node.h"


int main(int argc, char *argv[]){


	if (argc != 4){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	char *method = argv[1];
	char *filein = argv[2];
	char *fileout = argv[3];

	int size = determineSize(filein);
	int **puzzle = readFile(filein, size);
	
	



	int h= 0;
	


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










