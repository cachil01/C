#include "queue.h"



QUEUE *initQueue(tree_node *root){
	FRONTIER_NODE *n = NULL;
	n = (FRONTIER_NODE*) malloc(sizeof(FRONTIER_NODE));
	if(n == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}	

	n->leaf = root;
	n->next = NULL;
	n->previous = NULL;



	QUEUE *q = NULL;
	q = (QUEUE *) malloc(sizeof(QUEUE));
	if(q == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	
	q->search_tree = root;
	q->frontier_head = n;
	q->frontier_tail = n;

	return q;  
	

}

int enqueue(QUEUE *q, frontier_node *n){

	return 0;

}




















