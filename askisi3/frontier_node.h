#ifndef FRONTIER_NODE
#define FRONTIER_NODE

typedef struct frontier_node{

	TREE_NODE *leaf;
	struct frontier_node *next;
	struct frontier_node *previous;	


} FRONTIER_NODE;

typedef struct {

	tree_node *search_tree;
	frontier_node *frontier_head;
	frontier_node *frontier_tail;
	int size;

} QUEUE;


QUEUE *initQueue(tree_node *root);


#endif
