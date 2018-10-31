#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "tree_node.h"

/**
* @brief This is the struct of the FRONTIER_NODEs that get enqueued and dequeued in and out of the queue. 
*
*
*/
typedef struct frontier_node{

	TREE_NODE *leaf;
	struct frontier_node *next;
	struct frontier_node *previous;	


} FRONTIER_NODE;

/**
* @brief This is the struct of the QUEUE that holds the FRONTIER_NODEs 
*
*
*/
typedef struct {

	TREE_NODE *search_tree;
	FRONTIER_NODE *frontier_head;
	FRONTIER_NODE *frontier_tail;
	int size;

} QUEUE;

/**
* @brief This function initalizes a QUEUE and returns it
*
* 
*
*
* @param root This is the TREE_NODE that will become the root of the tree. 
* @return QUEUE returns an empty queue with root of the search tree a FRONTIER_NODE made with the parameter root.
*/
QUEUE *initQueue(TREE_NODE *root);


/**
* @brief This function enqueues a TREE_NODE in the queue
*
* Since the queue holds FRONTIER_NODEs it first makes one using the TREE_NODE given as parameter t.
* Then it enqueues that node.
*
*
* @param q This is the queue in which the node will be enqueued in
* @param t TREE_NODE that is used to make the new FRONTIER_NODE that will be enqueued in the queue.
* @return int Returns a 0 when it is successfull. -1 when an error occured.
*/
int enqueue(QUEUE *q, TREE_NODE *t);

/**
* @brief This function enqueues a TREE_NODE in the queue in an ascending order depending on the manhattan value of the node.
*
* Since the queue holds FRONTIER_NODEs it first makes one using the TREE_NODE given as parameter t.
* Then it enqueues that node based on the manhattan value.
* This function is used by the best method of finding a solution
*
* @param q This is the queue in which the node will be enqueued in
* @param t TREE_NODE that is used to make the new FRONTIER_NODE that will be enqueued in the queue.
* @return int Returns a 0 when it is successfull. -1 when an error occured.
*/
int sortedEnqueue(QUEUE *q, TREE_NODE *t);

/**
* @brief This function enqueues a TREE_NODE in the queue in an ascending order depending on the manhattan value of the node plus the depth of the node.
*
* Since the queue holds FRONTIER_NODEs it first makes one using the TREE_NODE given as parameter t.
* Then it enqueues that node based on the manhattan value.
* This function is used by the a-star method of finding a solution
*
* @param q This is the queue in which the node will be enqueued in
* @param t TREE_NODE that is used to make the new FRONTIER_NODE that will be enqueued in the queue.
* @return int Returns a 0 when it is successfull. -1 when an error occured.
*/
int sortedEnqueue2(QUEUE *q, TREE_NODE *t);

/**
* @brief This function dequeues a TREE_NODE in the queue
*
* Since the queue holds FRONTIER_NODEs but it returns a TREE_NODE the FRONTIER_NODE is freed from memory before
* the TREE_NODE is returned.
*
*
* @param q This is the queue from which the node will be dequeued.
* @return TREE_NODE Returns a pointer to the TREE_NODE that was in the head of the queue.
*/
TREE_NODE *dequeue(QUEUE *q);

#endif
