#ifndef __RUN_H__
#define __RUN_H__



int determineSize(char *filein);

int ** readFile(char *filein, int size);

int runMethod(QUEUE *q, int size, char *fileout, int code);









#endif