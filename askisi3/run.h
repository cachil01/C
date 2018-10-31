#ifndef __RUN_H__
#define __RUN_H__


/**
* @brief This function reads the lines of the input file to determine the size of the puzzle.
*
*
* @param *filein The name of the input file.
* @return int The size of the puzzle.
*/
int determineSize(char *filein);

/**
* @brief This function reads the input file and allocates the memory and stores in it the puzzle.
*
*
* @param *filein The name of the input file.
* @param size The size of the puzzle.
* @return int** The double pointer that points to the puzzle.
*/
int ** readFile(char *filein, int size);

/**
* @brief This function enqueues and dequeues node from the stack and searches for the solution.
*
* This funtion enqueues differently based on the method pased in the form of a code and based on it either the best, a-star o breadth algorithms are run.
*
* @param *q This is the queue that holds the nodes for the program.
* @param *fileout This is name of the output file that will hold the solution.
* @param code This is the code that indicates the algorithm for finding the solution. 0 is breadth, 1 is best, 2 is a-star.
* @return int Returns 0 if the solution is found or 1 if its not found.
*/
int runMethod(QUEUE *q, int size, char *fileout, int code);









#endif