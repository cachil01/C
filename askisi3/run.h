#ifndef __RUN_H__
#define __RUN_H__



int determineSize(char *filein);

int ** readFile(char *filein, int size);

int runBreadth(QUEUE *q, int size, char *fileout);







#endif