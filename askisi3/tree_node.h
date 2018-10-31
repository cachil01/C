#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

/**
* @brief This is the struct of the TREE_NODEs that get enqueued and dequeued in and out of the queue. 
*
*
*/
typedef struct tree_node
{
	int **puzzle;
	int g;
	int h;
	int move;
	struct tree_node *parent;
	struct tree_node *children[4];
} TREE_NODE;

/**
* @brief This function initializes a TREE_NODE and makes the p pointer parameter to point to it.
*
* The TREE_NODE holds a state of the puzzle. Also it holds the node that is its parent and the move that created it.
*
*
* @param **p This is a pointer to the address that holds the pointer to the TREE_NODE that is in the function that called this function.
* @param **puzzle This is the puzzle state that will be stored in the TREE_NODE.
* @param g This is the depth of the node.
* @param h This is the manhattan value of this state of the puzzle and it indicates the distance from the solution.
* @param *parent This is the TREE_NODE that was used to create the new state of the puzzle.
* @param move This is the move that was used on the previous state of the puzzle to create this one. 0 is right, 1 is down, 2 is left, 3 is up.
* @return int Returns a 0 when it is successfull. -1 when an error occured.
*/
int initTreeNode(TREE_NODE **p, int **puzzle, int g, int h, TREE_NODE *parent, int move);

/**
* @brief This function makes a child of a parent node with the move provided and returns the TREE_NODE.
*
* 
*
* @param *parent This is the TREE_NODE that is used to create the new state of the puzzle.
* @param move This is the move that is used on the parent's state of the puzzle to create the new one. 0 is right, 1 is down, 2 is left, 3 is up.
* @return TREE_NODE Returns the new TREE_NODE that is the child of the parent.
*/
TREE_NODE *makeChild(TREE_NODE *parent, int move, int size);

/**
* @brief This function checks if the state of the puzzle given has appeared in any of the ansestral nodes.
*
* It works recursively to see each ancestor's state of the puzzle and compares. If a same appears then it ends the recursion or until a NULL parent is seen(meaning no more ancestors).
*
* @param **puzzle This is the state of the puzzle that we want to see if it has already appeared.
* @param *parent This is the TREE_NODE that will be checked if it contains the given state of the puzzle.
* @param size This is the size of the puzzle.
* @return TREE_NODE Returns the new TREE_NODE that is the child of the parent.
*/
int nodeExist(int **puzzle, TREE_NODE *parent, int size);

/**
* @brief This function checks if the given move will place the puzzle out of bounds.
*
* It works by checking the current state and the move it wants to make. It checks the boundary to which the move is headed towards.
*
* @param *p This is the TREE_NODE that holds the state of the puzzle that wants to attempt to move.
* @param move This is the move that function will check.
* @param size This is the size of the puzzle.
* @return int Returns 0 if the move is possible and 1 if its not possible.
*/
int validMove(TREE_NODE *p, int move, int size);

/**
* @brief This function prints recursively the number of moves and each move required to reach the given node's state of the puzzle. 
*
* This funtion is used to print the steps to reach the solution. It can also be used for any other node that is not a solution.
*
* @param *node This is the TREE_NODE that holds the state of the puzzle that will have all the moves that lead to it printed.
* @param *count This holds a pointer to an int that holds a counter to count the number of moves that lead to the given node.
* @param *fp This is a file pointer so the solution can be printed in the output file.
* @return void
*/
void printSolution(TREE_NODE *node, int *count, FILE *fp);

/**
* @brief This function calculates the manhattan value of the puzzle state.
*
* The manhattan value is a heuristic that can be used to check relatively how far the puzzle is from the solution. Can also be used to see if its at the solution state.
*
* @param **puzzle This is the state of the puzzle that we want to calculate its manhattan value.
* @param size The size of the puzzle.
* @return int The manhattan value.
*/
int manhattan(int **puzzle, int size);




#endif
