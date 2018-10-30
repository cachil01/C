#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "tree_node.h"


typedef struct frontier_node{

	TREE_NODE *leaf;
	struct frontier_node *next;
	struct frontier_node *previous;	


} FRONTIER_NODE;

typedef struct {

	TREE_NODE *search_tree;
	FRONTIER_NODE *frontier_head;
	FRONTIER_NODE *frontier_tail;
	int size;

} QUEUE;


QUEUE *initQueue(TREE_NODE *root);

int enqueue(QUEUE *q, TREE_NODE *t);

int sortedEnqueue(QUEUE *q, TREE_NODE *t);

int sortedEnqueue2(QUEUE *q, TREE_NODE *t);

TREE_NODE *dequeue(QUEUE *q);

#endif
