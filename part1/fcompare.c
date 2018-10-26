/**
* @file fcompare.c
* @brief This is a program compares two text files line by line and prints any missmatching lines 
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

//Macro for converting an uppercase character to a lowercase
#define  lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' -'A'): (x))


void compareFiles(char *, char*, int);


/**
* @brief This is the main funtion. 
*
* 
* The program decides based on command line arguments if it will use any features through /ln /s /nc
*
*
* @param argc The number of arguments given through the command prompt
* @param argv The arguments given through the command prompt
* @return returns 0 when finished
*/
int main (int argc, char *argv[]){


	int code1=0;
	int code2=0;
	int code3=0;

	if (argc  < 3){

		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	
	int i ;                                            // Here the options are read and 
							   // and any extra are ignored.
	char *t;
	for (i = 1; i< argc; i++){
		t = argv[i];
		if (*t == '/'){
			t++;
			if(*t == 's'){
				code2 = 1;	
			}

			if(*t == 'l'){
				t++;
				if (*t == 'n'){
					code3 =1;

				}
				t--;
			}
			if(*t == 'n'){
				t++;
				if(*t == 'c'){
					code1=1;
				}
				t--;
			}

		}

	}
	

	int code = code1 + 2*code2 + 4*code3;
	char *filename1;
	char *filename2;
	filename1 = argv[argc-2];
	filename2 = argv[argc-1];
	
	compareFiles(filename1, filename2, code);


    return 0;
}

/**
* @brief This function opens the files and reads them. It then proceeds to compare them and print the * * * missmatches.
*
*
*
*
* @param  filename1 This is the name of the first file.
* @param filename2 This is the name of the second file.
* @param code This is the code that indicates what options were chosen.
* @return void
*/
void compareFiles( char *filename1, char *filename2, int code  ){
	
	FILE *fp = fopen(filename1, "r");	// Here the file is opened for reading
	FILE *fp2 = fopen(filename2, "r" );
	if(fp == NULL || fp2 == NULL ){
		printf("Failed to open file\n"); // Error message in case the file cant be opened
		exit(-1);
	}

	

	int flag =1;
	int flag2 =0;
	int count =1;
	char temp[60]= {};
	char temp2[60] = {};
	char lastLine1[60] = {};
	char lastLine2[60] = {};
	
	while (fgets(temp, 60, fp )!= NULL && fgets(temp2, 60, fp2) != NULL){

	
		
		if (code == 1 || code == 3 || code == 5 || code == 7){
			int t=0;
			
			while (temp[t] != '\0'){
				temp[t] = lcase(temp[t]);
				t++;
			}
			t=0;
			
			while(temp2[t] != '\0'){
				temp2[t] = lcase(temp2[t]);
				t++;
				
			}

			
			
		}

		if (strcmp(temp, temp2) != 0){
			if(flag == 1){
				flag =0;

				if (code == 4 || code == 5 || code == 6 || code == 7){
					printf("%d: ", count);
				}
		
				int p;
				for(p = 0; temp[p]!= '\0'; p++){
					printf("%c", temp[p]);
				}
		
				if(code == 4 || code == 5 || code == 6 || code == 7){
					printf("%d: ", count);
	
				}
				for(p =0; temp2[p] != '\0' ; p++){
					printf("%c", temp2[p]);

				}
				flag2++;
			}
			flag2++;
	
						
		}
		else{

			if(flag == 0 && flag2 >1){
				printf("Down to\n");
				if(code == 4 || code == 5 || code ==6 || code ==7){
					printf("%d: ", count-1);
				}
				printf("%s", lastLine1);
				if(code == 4|| code ==5 || code ==6|| code == 7){
					printf("%d: ", count-1);
				}
				printf("%s", lastLine2);
				flag =1;
				flag2 =0;
			}
			
			flag =1;
			flag2 =0;

			
		}
	
		count++;

		strcpy(lastLine1, temp);
		strcpy(lastLine2, temp2);
	}
	if(flag == 0 && flag2 >1){

		printf("Down to\n");
		if(code == 4 || code ==5 || code == 6|| code == 7){
			printf("%d: ", count-1);

		}
		printf("%s", lastLine1);
		if(code == 4 || code == 5 || code == 6 || code ==7){
			printf("%d: ", count-1);
		}
		printf("%s\n", lastLine2);
		


	}
		
	
	fclose(fp);
	fclose(fp2);

}

