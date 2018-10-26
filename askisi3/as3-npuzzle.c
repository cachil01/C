//#include "tree.h"
//#include "frontier_node.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	printf("Break: 1\n");
	if (argc != 4){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *filein = argv[2];
	char *fileout = argv[3];
	printf("Break: 2\n");

	//TREE_NODE *p = NULL;
	int **puzzle = NULL;
	printf("Break: 2.5\n");

	int size = readFile(filein, &puzzle);	
	printf("Break: 7\n");

	int **row = NULL;
	int *collumn = NULL;
	row= puzzle;
	
	printf("testing the readfile\n\n");
	
	int i,k;
	for(i = 0;i<size;i++){
		
		collumn = *row;
		for(k =0;k<size;k++){
			printf("%d ",*collumn);
			collumn++;
		}
		printf("\n");
		row++;
	}

	

}

int readFile(char *filein, int ***puzzle){

	FILE *fp = NULL;
	fp = fopen(filein, "r");

	if(fp == NULL){
		
		printf("Cannot open file\n");

		exit(EXIT_FAILURE);
	}
	
	printf("Break: 3\n");


	
	int count;
	char * tmp = (char*) malloc(sizeof(char)*100);
	while(fgets(tmp, 100, fp) != NULL){
		count++;
	}


	printf("Break: 4\n");


	int **temp = NULL;
	int *temp2 = NULL;
	*puzzle  = (int **) malloc(sizeof(int*)*count);
	temp = *puzzle;
	int i;
	
	printf("Break: 5\n");
	for(i=0;i<count;i++){
		*temp =(int*)malloc(sizeof(int)*count);
		temp++; 

	}
	 
	rewind(fp);
	temp = *puzzle;
	printf("Break: 6\n");


	char *hp = NULL;
	while(fgets(tmp, 100, fp) != NULL){
		hp = tmp;
		while(*hp!= '\0'){
			temp2 = *temp;
			if(*hp != '\t' && *hp!= '\n'){
				*temp2 = *hp - '0';
				temp2++;	
			}
			hp++;

		}

		
	}

	
	
	return count;
}








