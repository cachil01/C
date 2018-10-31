/**
* @file as3-npuzzle.c
* @brief This is a program that solves a Tile-Puzzle also known as a Sliding-Block game.
*
* The program takes as input a txt file and an output txt file as well as the method to solve the problem with
* (breadth, best , a-star). The command format is ./executable method input.txt output.txt .
* The program is compiled using the make command inside the directory of the .c and .h files.
* The program works by enqueing the enitial root node in the queue. Then the queue is dequeued and for each node 
* dequeued the program creates its children and checks if one of them is the solution. If not then the children are enqueue 
* using the method of the requested algorithm.
* 
*
*
*
* @author Christakis Achilleos
* @bug No known bugs. 
*
*
*
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue.h"
#include "run.h"
#include "tree_node.h"

/**
* @brief This is the main funtion. 
*
* This function calls finctions of the queue.c tree.c and run.c files to solve the puzzle.
* 
*
*
* @param argc The number of arguments given through the command prompt
* @param argv The arguments given through the command prompt
* @return returns 0 when finished
*/
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
	
	if(strcmp(method, "breadth") == 0){				//Run with breadth method
		int res =runMethod(q, size, fileout, 0);
		if(res == 1){
			printf("The solution was not found\n");
			return 0;
		}
	}
	else if(strcmp(method, "best") == 0){			//Run with best method
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










