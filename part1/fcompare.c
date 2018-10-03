#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Macro for converting an uppercase character to a lowercase
#define  lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' -'A'): (x))

char makelc(char);
void compareFiles(char *, char*, int);
int main (int argc, char *argv[]){


	int code1=0;
	int code2=0;
	int code3=0;

	if (argc  < 3){

		printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	
	int i ;
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


void compareFiles( char *filename1, char *filename2, int code  ){
	
	FILE *fp = fopen(filename1, "r");	// Here the file is opened for reading
	FILE *fp2 = fopen(filename2, "r" );
	if(fp == NULL || fp2 == NULL ){
		printf("Failed to open file\n"); // Error message in case the file cant be opened
		exit(-1);
	}

	printf("The code is %d\n", code);	

	int flag =1;
	int count =1;
	char temp[60]= {};
	char temp2[60] = {};
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

			flag =0;
			//printf("The line %d is not equal\n", count);
			if (code == 4 || code == 5 || code == 6 || code == 7){
				printf("%d: ", count);
			}

			int p;
			for(p = 0; temp[p]!= '\0'; p++){
				printf("%c", temp[p]);
			}
		//	printf("\n");
			if(code == 4 || code == 5 || code == 6 || code == 7){
				printf("%d: ", count);

			}
			for(p =0; temp2[p] != '\0' ; p++){
				printf("%c", temp2[p]);

			}
		//	printf("\n");
						
		}
	
		count++;


	}
		
	printf("\n%d lines read\n", count);



	if(flag ==1){

		printf("the files are the same\n");
	}
	else{

		printf("the files are not the same\n");

	}
	fclose(fp);
	fclose(fp2);





}


char makelc(char c){

	if (c>='A' && c<='Z'){

		return c + ('a' -'A');

	}

	return c;

}
