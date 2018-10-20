#ifndef TREE_NODE
#define TREE_NODE

typedef struct tree_node
{
	int **puzzle;
	int g;
	int h;
	struct tree_node *parent;
	struct tree_node *children[4];
} TREE_NODE;

#endif
