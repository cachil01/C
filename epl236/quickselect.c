/** @file quickselect.c
 *  @brief This is the source file that is responsible for the implementation
 *  of the quickselect algorithm
 *
 *  @author Christakis Achilleos 
 *  @bug No known bugs. 
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int swap (int *, int *);
int partition(int *, int, int);
int ksmallest(int *, int , int);

int quickselect(int * table, int left , int right, int k){
   int p = partition (table , left, right);
   if (p == k -1) {
      return table[p];

   }
   else if (k -1 < p ){
      return quickselect(table, left, p-1, k);
   }
   else {
      return quickselect(table , p +1, right, k);
   }

}

int partition(int *table, int low, int high){
   int pivot = table[high];
   int i = low ;
   int j;
   for (j = low; j< high ; j++){
      if (table[j] < pivot){
         i++;
         swap(&table[i], &table[j]);
      }
   }
   swap(&table[i +1] , &table[high]);
   return (i+1);

}

int swap(int *s, int *p){
   int t = *s;
   *s = *p ;
   *p = t;
   return EXIT_SUCCESS;
}
int ksmallest(int *table , int n, int k){
   int left = 0;
   int right = n- 1;
   int next = 1;
   return quickselect(table, left , right, k);

}


int main(int argc, char *argv[]){

   int size = atoi(argv[1]);
   int  * table = (int *) malloc(sizeof(int) * size) ;
   int i, num;
   srand((unsigned) time(NULL));
   for(i = 0 ; i< size ; i++){
      table[i] = rand() % (size+10);
      printf("%d\n", table[i]);

   }
   
   int pivot = rand() %size;
   printf("-------------------------------------\n");
   int res = ksmallest(table,  size, size/2);
   for(i = 0 ; i< size ; i++){
   //   table[i] = rand() % (size+10);
      printf("%d\n", table[i]);
   } 
   printf("\nThe median is : %d\n ", res);

   return EXIT_SUCCESS;
}

