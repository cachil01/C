/**
* @file pagerank.c
* @brief This is a program compares two text files line by line and prints any missmatching lines 
*
*
* @author Christakis Achilleos
* @bug No known bugs. 
*
*
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
* @brief This is the main funtion. 
*
* 
* The program opens the two files and stores the data in the heap with the use of the malloc function. 
* After the data is stored in tables it gets processed to get the pagerank for each site.
* In the end the results are printed on stdout.
* 
*
* @param argc The number of arguments given through the command prompt
* @param argv The arguments given through the command prompt
* @return returns 0 when finished
*/
int main(int argc, char *argv[]){



    int **visits = (int **)malloc( sizeof(int*));
    char **names = (char **)malloc(sizeof(char*));
    int *tags = (int*)malloc(sizeof(int));



	
	
    if (argc !=3){

        printf("Wrong number of arguments.\n");
        exit(EXIT_FAILURE);
    }


    char *filename1 = argv[1];
    char *filename2 = argv[2];

    FILE *fp1;
    FILE *fp2;
   
    fp1 = fopen(filename1, "r");

    if(fp1 == NULL){

        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(filename2, "r");

    if(fp2 == NULL) {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }


    
    int size =1;
    int count =0;
    char string[100];

    while(fgets(string, 100, fp1) != NULL){              // Here the first file is read that contains the hostnames

        char* t = NULL;
        t = strtok(string, " ");
        tags[count] = atoi(t);
        t = strtok(NULL, "\n");
        names[count]  = (char*)malloc(sizeof(char) * strlen(t));
        strcpy(names[count], t);

        if(count == size){
            size *=2;
            char **tempNames = (char **) realloc(names, sizeof(char*) * size);
            if(tempNames==NULL){
                printf("Failed to reallocate memory.");
                exit(EXIT_FAILURE);

            }
            names= tempNames;
            int *tempTags = (int*)realloc(tags , sizeof(int)*size);
            if(tempTags == NULL){
                printf("Failed to allocate memory.");
                exit(EXIT_FAILURE);
            }
            tags = tempTags;

        }


        count++;
    }  


    

    printf("%d\n", count);				// Here the table that holds the amount of hyperlinks to each host increases depending on the number of hosts.

    int **tempVisits = (int **)realloc(visits, count*sizeof(int*));
    if(tempVisits == NULL){
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    visits =tempVisits;


    

    char *t = NULL;

   while(fgets(string,sizeof(string),fp2)){		// The second file is read.
      int k = 0;
      int numbers[100];
      t = strtok(string, " ->:");
      while (t != NULL) {
         numbers[k++] = atoi(t);
         t = strtok (NULL, " ->:");
      }

      int row = numbers[0];
      visits[row] = (int *)calloc(count,sizeof(int));

      if (k == 2){
         continue;
      }else if (k%2 == 0){
         printf("This file has wrong data\n");
      }else{
         int j=0;
         for (j=1;j<k;j+=2){
            int col = numbers[j];
            visits[row][col] = numbers[j+1];
         }
      }
   }




    fclose(fp1);
    fclose(fp2);

	
    printf("+++ Start of printing structure Oij +++\n");
    printf("The structure of each line is:\n");
    printf("src -> dest1:nlinks1 dest2:nlinks2 ... destk:nlinksk\n\n");
    
    

    int i,j;
    for(i=0;i<count;i++){
        printf("%d ->", tags[i]);
        for(j =0;j<count;j++){
            if(visits[i][j]!=0){
                printf(" %d:%d", j, visits[i][j]);
            }
        }
        printf("\n");
    }




    printf("\n");
    printf("--- End of printing structure Oij ---");
    printf("\n\n\n");
    printf("+++ Start of printing structure Oj +++\n");
    printf("The structure of each line is:\n");
    printf("src ==> links_total\n\n");

    int *Oj = (int *)calloc(count,sizeof(int));
    
    for (i=0;i<count;i++){
        printf("%d ==>",tags[i]);
        int sumOfConnections = 0;
        for (j=0;j<count;j++){
            sumOfConnections += visits[i][j];   
        }
        Oj[i] = sumOfConnections;
        printf(" %d\n", Oj[i]);
    }
		
	
	printf("\n");
    printf("---End of printing structure Oj ---");
    printf("\n\n\n");
    printf("+++ Start of printing structure Iij +++\n");
    printf("The structure of each line is:\n");
    printf("dest <== hosts_total hostid1 hostid2 ... hostidk\n\n");
	
    int sum=0;

    for (i=0;i<count;i++){
        printf("%d <==",tags[i]);
        sum=0;
        for (j=0;j<count;j++){
            if (visits[j][i] != 0){
                sum++;
            }   
        }
        printf(" %d\t", sum);
        for (j=0;j<count;j++){
            int sum=0;
            if (visits[j][i] != 0){
                printf(" %d", tags[j]);
            }   
        }
        printf("\n");
    }

    printf("\n");
    printf("--- End of printing structure Iij ---"); 
    printf("\n\n\n");
    printf("+++ Start of printing PR +++\n\n");

    float PRi[i];              		
    float PRi1[i];
    int position;
    for (position=0;position<i;position++){
       PRi[position] = 1;
    }
    float distance = 1.0;

    while(!(distance<=(0.02))){			// The pagerank is calculated.
      int m,n;
      float total;
      for (m = 0;m<i;m++){
         total = 0.0;
         for(n=0;n<i;n++){
            if (Oj[n]!=0){
               float sum = PRi[n]*visits[n][m]/Oj[n];
               total += sum;
            }
         }
         PRi1[m] = (1-0.85)/i + 0.85 * total ;
  
      }
   
      float distanceTotal = 0.0;
      for (i=0;i<count;i++){
         distanceTotal+= (PRi[i]-PRi1[i]) * (PRi[i]-PRi1[i]);
         PRi[i] = PRi1[i];
      }
      distance = sqrt(distanceTotal);
   }


   float total = 0.0;
   for (i=0;i<count;i++){
      total+= PRi[i];
   }

   printf("host_id\t\thosts_rank\tnorm_host_rank\thosts_name\n");
   int x;
   
    char tempC[6] = {};

    

    
    for(x=0; x<count ;x++){
        
	printf("%d\t\t%.3f\t\t%.2f\t\t%s\n", tags[x], PRi[x], PRi[x]/total, names[x]);

   
        
    }



    
    printf("\n\n--- End of printing PR --- \n");
    
    
    
    return 0;
}



