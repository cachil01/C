
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
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
int runMethod(QUEUE *q, int size, char *fileout, int code){
	int i;
	while(q->size != 0){
			
			TREE_NODE *b =NULL;
			b = dequeue(q);
			//printf("dequeued a child\n");
			
			
			for(i =0; i<4;i++){
				TREE_NODE *temp= NULL;
				
				temp = makeChild(b , i, size);
				if(temp != NULL){
					/*int p, m;
					for(p = 0;p<size;p++){
						for(m =0;m<size;m++){
							printf("%d ",temp->puzzle[p][m]);
						}
						printf("\n");
								
					}
					printf("\n");*/
					//printf("made a child!\n");
					//printf("The manhattan number is: %d\n", temp->h);
					if(temp->h == 0){
						printf("solution was found\n");
							//int p, m;
							/*for(p = 0;p<size;p++){
								for(m =0;m<size;m++){
									printf("%d ",temp->puzzle[p][m]);
								}
								printf("\n");
							}*/
							
							
						FILE *fp = NULL;
						fp = fopen(fileout, "w");
						if( fp == NULL){
							printf("FAILED TO OPEN FILE\n");
							exit(EXIT_FAILURE);
						}
						int count =0;
						printf("\n");
						printSolution(temp, &count, fp);
						fclose(fp);
						return 0;
					}
					else{
						
						//printf("enqueued a child\n");
						switch (code){
						
							case 0:
							enqueue(q,temp);
							break;
							
							case 1:
							sortedEnqueue(q, temp);
							break;
							
							case 2:
							sortedEnqueue(q, temp);
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
	
	/*int **puzzle = (int**)malloc(sizeof(int*)*size);
	
	if(puzzle == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}*/


	printf("Break: 4\n");


	int **temp = NULL;
	int *temp2 = NULL;
	int **puzzle  = (int **) malloc(sizeof(int*)*size);
	
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



	//char *hp = NULL;
	while(fgets(tmp, 100, fp) != NULL){
		//hp = tmp;
		temp2 = *temp;
		/*while(*hp!= '\0'){
			
			if(*hp != '\t' && *hp!= '\n' && *hp != '\0'){
				*temp2 = *hp - '0';
				temp2++;	
			}
			hp++;

		}*/
		
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