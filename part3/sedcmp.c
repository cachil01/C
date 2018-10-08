/**
* @file sedcmp.c
* @brief This is a program compares two strings and calculates the distance between 
*
*
*
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

// This is a macro for comparing 3 numbers and finding the minimum
#define MIN(X,Z,Y) ( (X) < (Z) ? ( (X) < (Y) ? (X) : (Y)) : ( (Z) < (Y) ? (Z) : (Y)) )

int sed(char*, char*, int, int);


/**
* @brief This is the main funtion. 
*
* This function calls the sed function that calculates the minimum number of steps.
* 
*
*
* @param argc The number of arguments given through the command prompt
* @param argv The arguments given through the command prompt
* @return returns 0 when finished
*/
int main(int argc, char *argv[]){



	if (argc!=3){
		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *filename1;
	char*filename2;

	filename1 = argv[1];
	filename2= argv[2];

	FILE *fp1 = fopen(filename1, "r");
	FILE *fp2 = fopen(filename2, "r");

	if(fp1 ==NULL || fp2 == NULL){
		printf("Failed to open file\n");
		exit(EXIT_FAILURE);
	}


	int size1 ;
	int size2 ;

	
	
	int count1 = 0;
	int count2 = 0;
	char temp1[200];
	char temp2[200];
	if(fgets(temp1, 200,fp1) == NULL){
		printf("Failed to read line.\n");
	}
	if (fgets(temp2, 200,fp2) == NULL ){
		printf("failed to read line.\n");
	}
	
	size1 = strlen(temp1);
	size2 = strlen(temp2);

	char *table1 = (char *) malloc(sizeof(char) * size1);
	char *table2 = (char *) malloc(sizeof(char) * size2);

	
	if (table1 == NULL || table2 == NULL){
		printf("Failed to allocate memory. Exiting.\n");
		exit(EXIT_FAILURE);

	}

	memcpy( table1, temp1, size1);
	memcpy( table2, temp2, size2);

	
	
	
	
	int num = sedC(table1, table2, size1, size2);


	printf("Minimum edits required to conver is %d\n", num);
	
	
	return 0;


}

/**
* @brief This function uses
*
* This function calls the sed function that calculates the minimum number of steps.
* 
*
*
* @param argc The number of arguments given through the command prompt
* @param argv The arguments given through the command prompt
* @return returns 0 when finished
*/


int sedC(char * str1, char * str2, int m, int n) 
{ 

	int j;
	int i;
    // Create a table to store results of subproblems 
    int dp[m+1][n+1]; 
  
    // Fill d[][] in bottom up manner 
    for ( i=0; i<=m; i++) 
    { 
        for ( j=0; j<=n; j++) 
        { 
            //Here if the first string is empty then we have to insert
	    //all characters from the second string
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            //Here if the second string is empty then we have to insert
	    //all characters from the first string
            else if (j==0) 
                dp[i][j] = i; 
  
            //Here if the last part is the same then ignore it and proceed with the rest
            else if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
  
            // In case the last is different then check which option is minimum
            else
                dp[i][j] = 1 + MIN(dp[i][j-1],  // Here we check for inserting a char
                                   dp[i-1][j],  // Here we check for deleting a char
                                   dp[i-1][j-1]); // Here we check for replacing a character. 
        } 
    } 
  
    return dp[m][n]; 
} 



