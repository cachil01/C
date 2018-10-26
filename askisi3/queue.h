#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct tree_node
{
	int **puzzle;
	int g;
	int h;
	struct tree_node *parent;
	struct tree_node *children[4];
} TREE_NODE;


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

int enqueue(QUEUE *q, TREE_NODE *n);

FRONTIER_NODE *dequeue(QUEUE *q);

#endif
