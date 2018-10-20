#include <stdio.h>
#include <stdlib.h>
#include "TREE_NODE.h"


int main(int*argc, char *argv[]){

	if (*argc != 4){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *filein = argv[2];
	char *fileout = argv[3];

	TREE_NODE *p = NULL;

}
