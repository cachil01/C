#ifndef __TREE_NODE__
#define __TREE_NODE__

typedef struct tree_node
{
	int **puzzle;
	int g;
	int h;
	struct tree_node *parent;
	struct tree_node *children[4];
} TREE_NODE;

#endif
