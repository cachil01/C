
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



QUEUE *initQueue(TREE_NODE *root){


	QUEUE *q = NULL;
	q = (QUEUE *) malloc(sizeof(QUEUE));
	if(q == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	
	q->search_tree = root;
	q->frontier_head = NULL;
	q->frontier_tail = NULL;
	q->size =0;
	return q;  
	

}

int enqueue(QUEUE *q, TREE_NODE *t){

	if(q == NULL) {
		printf("This is a NULL queue\n");
		return -1;
	}

	if (t == NULL){
		printf("The node is NULL \n");
		return -1;
	}

	FRONTIER_NODE *n = NULL;
	n = (FRONTIER_NODE*) malloc(sizeof(FRONTIER_NODE));
	if(n == NULL){
		printf("Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}	

	n->leaf = t;
	n->next = NULL;
	n->previous = NULL;

	if (q->size == 0){
		q->frontier_head = n;
		q->frontier_tail = n;
		q->size = 1;
		
	}
	else{
		q->frontier_tail->next = n;
		n->previous = q->frontier_tail;
		q->frontier_tail = n;
		
		(q->size)++;
	}








	return 0;

}

FRONTIER_NODE *dequeue(QUEUE *q){

	if(q == NULL){
		printf("This is a NULL queue\n");
		return NULL;
	}

	if(q->size == 0){
		printf("This queue is empty\n");
		return NULL;
	}

	if(q->size == 1){
		FRONTIER_NODE *t = NULL;
		t = q->frontier_head;
		q->frontier_tail = NULL;
		q->frontier_head = NULL;	
		(q->size)--;
		return t;

	}
	else{
		
		FRONTIER_NODE *t = NULL;
		t = q->frontier_head;
		q->frontier_head = t->next;
		t->next->previous = NULL;	
		(q->size)--;
		return t;
	}

}




















