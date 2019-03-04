#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * iterate thru string as taught in class. since i am reading directly from command line, i can use arg[v] to read each word. arg[v][i] gives the char of each word. i will not need to do any memory allocation for strings to do this using arg[v]. so thank the Lord!!! alhamdulillah
 *
 */

int main(int argc, char** argv){

	int i; int j; int consonants; int length; char* yay = "yay"; char* ay = "ay"; char space = ' '; 

	if (argc < 2) {
		printf("insufficient arguments");
		return 0;
	}

	for(i = 1; i < argc; i++) {
		//first the vowels case, 
		if (argv[i][0] == 'a' || argv[i][0] == 'A' || argv[i][0] == 'e' || argv[i][0] == 'E' || argv[i][0] == 'i' || argv[i][0] == 'I' || argv[i][0] == 'o' || argv[i][0] == 'O' || argv[i][0] == 'u' || argv[i][0] == 'U') {

			printf("%s",argv[i]);
			printf("%s", yay);
//			printf("%c", space);


		} else {
		//CONSONANTS IS NOT WORKINGGGGGGGGGGGGGG
consonants=0;
			length = strlen(argv[i]);
			for (j = 0; j < length; j++) {
				if (argv[i][j] != 'a' && argv[i][j] != 'A' && argv[i][j] != 'e' && argv[i][j] != 'E' && argv[i][j] != 'i' && argv[i][j] != 'I' && argv[i][j] != 'o' && argv[i][j] != 'O' && argv[i][j] != 'u' && argv[i][j] != 'U') {

//printf("AYESHAAYESHAYSHEAHSAEYJSAHEAHSYEHASYHEYH\n");

					consonants++;
					//printf("%d", consonants);
				} else if (argv[i][j] == 'a' || argv[i][j] == 'A' || argv[i][j] == 'e' || argv[i][j] == 'E' || argv[i][j] == 'i' || argv[i][j] == 'I' || argv[i][j] == 'o' || argv[i][j] == 'O' || argv[i][j] == 'u' || argv[i][j] == 'U' ) { 
					//printf("%c", argv[i][j];
					break;
				}
			}		
	
			//print the vowels first
			for (j = consonants; j < length; j++) {
	//			printf("the vowels are: %c", argv[i][j]);
				printf("%c",argv[i][j]);
			}
			
			//print the consonants
			for (j = 0; j < consonants; j++) {
				printf("%c", argv[i][j]);
			}
			
			//print ay
			printf("%s", ay);
			//print the space
//			printf("%c", space);
			
				
			}
	  printf("%c", space);

	}	 
//		printf("%c", space);
	printf("\n");
	return 0;
}
