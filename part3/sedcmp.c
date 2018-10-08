#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(X,Z,Y) ( (X) < (Z) ? ( (X) < (Y) ? (X) : (Y)) : ( (Z) < (Y) ? (Z) : (Y)) )

int sed(char*, char*, int, int);
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


	/*
	while((*dp1 = fgetc(fp1)) != EOF){
		
		count1 ++;
		printf("char is added: %c\n", *dp1);
		//printf("count1: %d\n", count1);

		if(count1 == size1){

			
			dp1 = NULL;
			temp1 = (char *) malloc(sizeof(char)*size1*2);
			if(temp1 == NULL){
				printf("Failed to allocate memory.Exiting.\n");
				exit(EXIT_FAILURE);
			}

			memcpy(temp1, table1, (size1)   * sizeof(char));
			free(table1);
			table1 = temp1;
			dp1 = table1 + (size1);
			size1*=2;
			
			temp1 =NULL;
		}
		dp1++;
	}*/
	
	/*
	while((*dp2 = fgetc(fp2)) != EOF){

		count2 ++;

		//printf("count2: %d\n", count2);

		if(count2 == size2){

			size2*=2;
			dp2 = NULL;
			temp2 = (char *) malloc(sizeof(char)*size2);
			if(temp2 == NULL){
				printf("Failed to allocate memory.Exiting.\n");
				exit(EXIT_FAILURE);
			}
			//printf("%c\n", *table2 );
			memcpy(temp2, table2, (size2/2)  * sizeof(char));
			free(table2);
			table2 = temp2;
			dp2 = table2 + size2/2;
			temp2 =NULL;
		}
		dp2++;




	}
	*/
	//*dp1 = '\0';
	//*dp2 ='\0';

	printf("size1 = %d , size2 = %d\n", size1, size2);
	
	
	
	
	int num = sedC(table1, table2, size1, size2);


	printf("Minimum edits required to conver is %d\n", num);
	
	
	



	return 0;


}


int sed(char *table1, char *table2, int size1, int size2){
	
	int temp ;

	if (size1 == 0){

		return size2;
	}

	if (size2 ==0){

		return size1;
	}

	if(table1[size1 - 1] == table2[size2 -1]){
		
		temp =0;
	}
	else {
		temp = 1;
	}
	
	int res1 = sed(table1 , table2, size1, size2-1);
	int res2 = sed(table1, table2, size1-1,size2);
	int res3 = sed(table1,table2, size1-1, size2-1);

	if (res1 < res2){

		if(res1 < res3){
			return 1+res1;
		}
		return temp+res3;


	}
	if(res2 < res3){
		return 1 +res2;
	}
	return temp+res3;

}

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
            // If first string is empty, only option is to 
            // isnert all characters of second string 
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j==0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + MIN(dp[i][j-1],  // Insert 
                                   dp[i-1][j],  // Remove 
                                   dp[i-1][j-1]); // Replace 
        } 
    } 
  
    return dp[m][n]; 
} 



