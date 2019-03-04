#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * read an input string. print out the last letter of each without spaces.
 *
 */

int main (int argc, char** argv) {


if (argc < 2 ) {
	printf("not enough arguments\n");
	return 0;
}

int i; int length = 0; int last = 0;

for (i = 1; i < argc; i++) {
	length = strlen(argv[i]);
	//now read the last letter of argv[i]
		last = length-1;
		printf("%c", argv[i][last]);

	


}



return 0;
}
