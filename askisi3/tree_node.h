#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

typedef struct tree_node
{
	int **puzzle;
	int g;
	int h;
	int move;
	struct tree_node *parent;
	struct tree_node *children[4];
} TREE_NODE;


int initTreeNode(TREE_NODE **p, int **puzzle, int g, int h, TREE_NODE *parent, int move);

TREE_NODE *makeChild(TREE_NODE *parent, int move, int size);

int nodeExist(int **puzzle, TREE_NODE *parent, int size);

int validMove(TREE_NODE *p, int move, int size);

void printSolution(TREE_NODE *node, int *count, FILE *fp);

int manhattan(int **puzzle, int size);




#endif
