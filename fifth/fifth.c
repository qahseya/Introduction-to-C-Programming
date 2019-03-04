#include<stdio.h>
#include<stdlib.h>

/*
 * the main idea is to traverse thru a 2d array via a matrix. take in the usual way. i must check to see if each row equals the magic sum. i really fucking hate math omg. ok so the rows have to equal the columns which have to equal the diagonal. 
 *
 * there are 4ish steps: 1. copy in the file and create the matrix using the steps learned in class. Make sure to also come up with the magic sum using the inputted size. 2. Check the rows, column, and diagonal sums to see if they eqyal the magicSum. AS SOON AS I FIND ONE DOES NOT EQUAL IT, I WILL IMMEDIATELY RETURN FALSE BECAUSE THERE IS NO USE CONTINUING!!!! 3. hope it fucking works.  
 */

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("not enough arguments \n");
		return 0;
	}

	FILE *fp; int size; int element;
	fp = fopen(argv[1], "r");
	if (fp == NULL) return 0;
	fscanf(fp, "%d\n", &size);
	
//declare the matrix and allocat ethe space

	int **matrix;
	matrix = (int**) malloc(size * sizeof(int *));

//initialize the initial matrix, row per row
	int i; int j;
	for (i = 0; i < size; i++) {
		matrix[i] = (int *) malloc(size * sizeof(int));
	}
//initialize the matrix IDK IF THIS WORKS YET THOOOO
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			fscanf(fp, "%d", &element);
			matrix[i][j] = element;
		}
	}

//NOW FOR FREAKING HOGWARTS VIBE YUNG MONEY YUSS

int rowSum = 0; int colSum = 0; int diagSum = 0; 
//int magSum = ((size * ((size^2) +1))/1);
//printf("magSum: %d\n", magSum);
//printf("size: %d\n", size);
	//SUM OF ROWS BISMILLAH AR RAHMAN AR RAHEEM
	//loop thru a for loop, and add up all the stuff in every row
	
	for (i = 0; i < size; i++) {
		for (j = 0; j< size; j++){ 
			rowSum += matrix[i][j]; //get the sum of the row
		}
/*		if (rowSum != magSum){ //before moving onto the next row, do a lil check up
		//	printf("row sum: %d\n", rowSum);
			printf("not-magic");
			return 0; //immediately exit
		}
*/
	}

	//SUM OF COLUMNS IDK IF THATS HOW U SPELL COLUMNS OR IF ITS COLLUMNS
	for (i= 0; i < size; i++) {
		for (j= 0; j< size; j++) {
			//colSum += mat[i][j]
			colSum += matrix[j][i]; //columns are all with the same value of j.
		}
		if (rowSum != colSum) {
		//	printf("colSum: %d\n", colSum);
			printf("not-magic");
			return 0;
		}
	}

	//DIAGONAL

// 	ok so there's many ways to do this. the diagonal always has the samen umber and the same number in i. recursively???? but i dont have time to fucking learn recursion in c. i can do [j][j] ? but that would require two loops right? if i do [i][i] then i might be able to do it in one loop. GO TO OFFICE HOURS FOR THIS

	for (i= 0; i < size; i++) {
		diagSum += matrix[i][i];
	}
	if (rowSum != diagSum) {
	//	printf("colSum: %d\n", diagSum);
		printf("not-magic");
		return 0;
	}

printf("magic");
return 0;
}
