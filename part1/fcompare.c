#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Macro for converting an uppercase character to a lowercase
#define  lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' -'A'): (x))



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
			{
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
	
	compare(filename1, filename2, code);


    return 0;
}

void compare( char *filename1, char *filename2, int code  ){
	
	FILE *fp = fopen(filename1, "r");	// Here the file is opened for reading
	FILE *fp2 = fopen(filename2, "r" );
	if(fp == NULL || fp2 == NULL ){
		printf("Failed to open file\n"); // Error message incase the file cant be opened
		exit(-1);
	}

	

	int flag =1;
	int count =0;
	char *temp;
	char *temp2;
	while (fgets(temp, 20, fp ) && fgets(temp2, 20, fp2)){

		
		if (code == 1 || code == 3 || code == 7){
			char *t = temp;
			
			while (*temp != '\0'){
				*temp = lcase(*temp);
				temp++;
			}
			temp = t;
			t = temp2;
			while(*temp2 != '\0'){
				*temp2 = lcase(*temp2);
				temp2++;
				
			}
			temp2 = t;

			
			
		}

		if (strcmp(temp, temp2) != 0){

			flag =0;
			printf("The line %d is not equal\n", count);

			
		}
	
		count++;


	}
		
	printf("%d lines read\n", count);



	if(flag ==1){

		printf("the files are the same\n");
	}
	else{

		printf("the files are not the same\n");

	}
	





}


char makelc(char c){

	if (c>='A' && c<='Z'){

		return c + ('a' -'A');

	}

	return c;



}
