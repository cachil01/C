#ifndef FRONTIER_NODE
#define FRONTIER_NODE

typedef struct frontier_node{

	TREE_NODE *leaf;
	struct frontier_node *next;
	struct frontier_node *previous;	


} FRONTIER_NODE;

#endif
