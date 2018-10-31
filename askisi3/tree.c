/**
* @file tree.c
* @brief This is the source file for the functions that have to do with TREE_NODEs
*
* It contains a function that creates a TREE_NODE, a function to create a child of a TREE_NODE , a function that calculates the manhattan value and a method to print
* the moves that created the node. Also contains two helping functions that are used be the makeChild function.
*
* @author Christakis Achilleos
* @bug No known bugs. 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"


int initTreeNode(TREE_NODE **p, int **puzzle, int g, int h, TREE_NODE *parent, int move){
	
	
	if (p==NULL || puzzle ==NULL){
		return -1;
	}
	
	TREE_NODE *z= (TREE_NODE *) malloc(sizeof(TREE_NODE));
	
	if(p == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	if(parent!= NULL){
		parent->children[move]=z;
	}
	z->g = g;
	z->h = h;
	z->puzzle = puzzle;
	z->parent = parent;
	z->move=move;
	z->children[0] =NULL;
	z->children[1] =NULL;
	z->children[2] =NULL;
	z->children[3] =NULL;
	
	*p =z;
	
	return 0;
}

int manhattan(int **puzzle, int size){
		int result=0;
		int i,j;
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				if(puzzle[i][j] ==0){
					continue;
				}
				if(puzzle[i][j]%size ==0){
					result = result +abs(i-((puzzle[i][j]/size)-1))+abs(j-(size-1));
				}
				else{
					result = result + abs(i-puzzle[i][j]/size)+abs(j-(puzzle[i][j]%size - 1));
				}
				
			}
			
		}
		
		return result;
}


TREE_NODE *makeChild(TREE_NODE *parent, int move, int size){
	
	if(validMove(parent, move, size) != 0){
		return NULL;
	}
	int **puzzle = NULL;
	puzzle = (int **)  malloc(sizeof(int*)*size);
	int i,j;
	
	
	for(i =0;i<size;i++){
		puzzle[i] = (int*) malloc(sizeof(int)*size);
	}
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			puzzle[i][j] = parent->puzzle[i][j];
		}
	}
	
	
	//find 0
	
	int pos[2]={0,0};
	
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			
			if(puzzle[i][j] == 0){
				pos[0]=i;
				pos[1]=j;
				
			}
			
		}
		
	}
	int tp =0;
	switch(move){
		case 0:
			tp = puzzle[pos[0]][pos[1]+1];
			puzzle[pos[0]][pos[1]+1] = 0;
			puzzle[pos[0]][pos[1]] = tp;
		
		
		break;
		
		case 1:
			tp = puzzle[pos[0]+1][pos[1]];
			puzzle[pos[0]+1][pos[1]] = 0;
			puzzle[pos[0]][pos[1]] = tp;
		
		
		break;
		
		case 2:
			tp = puzzle[pos[0]][pos[1]-1];
			puzzle[pos[0]][pos[1]-1] = 0;
			puzzle[pos[0]][pos[1]] = tp;
		
		break;
		
		
		
		case 3:
			tp = puzzle[pos[0]-1][pos[1]];
			puzzle[pos[0]-1][pos[1]] = 0;
			puzzle[pos[0]][pos[1]] = tp;
		
		break;
		
		
		
		
		default:
			printf("Invalid move\n");
			return NULL;
	}
	
	
	if(nodeExist(puzzle, parent, size) == 1)
		return NULL;
	else{
		TREE_NODE *p = NULL;
		int h = manhattan(puzzle, size);
		initTreeNode(&p, puzzle, (parent->g)+1, h, parent, move);
		
		return p;
		
	}
	
}


int validMove(TREE_NODE *p, int move, int size){
	
	int **temp = p->puzzle;
	int pos[2]={0,0};
	
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			
			if(temp[i][j] == 0){
				pos[0]=i;
				pos[1]=j;
				
			}
			
		}
		
	}
	
	if(move == 0){
		if(pos[1]==size-1)
			return 1;
	}
	else if(move ==1){
		if(pos[0]==size-1)
			return 1;
	}
	else if(move == 2){
		if(pos[1]==0)
			return 1;
	}
	else if(move == 3){
		if(pos[0]==0)
			return 1;
	}
	return 0;
	
}

int nodeExist(int **puzzle, TREE_NODE *parent, int size){
	
	if(parent == NULL){
		return 0;
	}
	
	int i,j;
	int flag =0;
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(puzzle[i][j] != parent->puzzle[i][j]){
				flag =1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	
	if (flag == 0){
		return 1;
	}
	else{
		return nodeExist(puzzle, parent->parent, size);
	}
	
	
}

void printSolution(TREE_NODE *node, int *count, FILE *fp){
	
	if(node->parent == NULL){
		
		fprintf(fp,"number of steps: %d\n", *count);
		return;
	}
	(*count)++;
	printSolution(node->parent, count, fp);
	
	switch(node->move){
		case 0:
		fprintf(fp,"right\n");
		break;
		
		case 1:
		fprintf(fp,"down\n");
		break;
		
		case 2:
		fprintf(fp,"left\n");
		break;
		
		case 3:
		fprintf(fp,"up\n");
		break;
		
	}
	
	return;
	
	
	
}











