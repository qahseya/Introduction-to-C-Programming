
#include<stdio.h>
#include<stdlib.h>

/*
 * so the only complicated part of this assignment is the memory allocation of the 3 matrices, and the way you read them in from a file. There are essentially 5 (large) steps. 
 *
 * 1. Open the file and read the first line. Malloc for a matrix whose initial malloc is the first number, and then the row allocation should be based of the second size.
 * 
 * 2. Read the values in the same way i did for the other multiplication problem. THIS MATRIX IS THE M1. The first number should also be used to do the initial malloc of RESULTANT matrix.
 *
 * 3. After this, i will once again be at a line with only two values. Allocate M2 using this. The second number of this row will do the inner allocation row-per-row of the resultant matrix. Leave these values as null, like how they were left in the file on sakai. 
 *
 * 4. do the multiplication the way it's done in the colSum and rowSum way of the matrix squares, but a little modified, except i havent figured that out yet. there's multiplication involved in addition to the addition lol punny.
 *
 * 5.  print out using nested for loop. i think this is in the sakai page.
 *
 */

int main (int argc, char** argv) {

	if (argc!= 2) {
		printf("not enough arguments \n");
		return 0;
	}

	//open file
	FILE *fp; int rowSize; int colSize;
	fp = fopen(argv[1], "r");
	if (fp == NULL) return 0;
	fscanf(fp, "%d %d\n", &rowSize, &colSize);
	int firstRow = rowSize;
	int firstCol= colSize;
//declare the matrix and allocate the space

	int **m1; int **result;
	m1 = (int**) malloc(firstRow * sizeof(int *));
	result = (int**) malloc(firstRow * sizeof(int *));

//initialize the rows of M1, row by row

	int i; int j;
	for (i = 0; i < firstRow; i++ ) {
		m1[i] = (int *) malloc(firstCol * sizeof(int));

	}

//initialize all the elements of the matrix
	int element;
	for (i = 0; i <firstRow; i++) {
		for (j = 0; j < firstCol; j++) {
			fscanf(fp, "%d", &element);
			m1[i][j] = element;
		}
	}

	int resRows = rowSize;
//I HAVE REACHED THE END of THE FIRST MATRIX. IDK IF THIS READS THE SECOND METHOD PROPERLY....
	fscanf(fp, "%d %d\n", &rowSize, &colSize);
	int secRow = rowSize;
	int secCol = colSize;

	if (firstCol != secRow) {
		printf("bad-matrices");
		return 0;
	}
//declare matrix2 and allocate the space

	int **m2;
	m2 = (int**) malloc(secRow * sizeof(int *));


//initialize the rows of M2, row by row. as well as the rows of result. 
	for (i = 0; i < secRow; i++) {
		m2[i] = (int *) malloc(secCol * sizeof(int));
	}

	for (i = 0; i < resRows; i ++) {
		result[i] = (int *) malloc(secCol * sizeof(int));
	}

//initialize all the elements of m2
	for (i = 0; i < secRow; i++) {
		for (j = 0; j < secCol; j++ ) {
			fscanf(fp, "%d", &element);
			m2[i][j] = element;
		}
	}

//initialize all the elements of result matrix

	for (i = 0; i < firstRow; i++ ) {
		for (j = 0; j < secCol; j++) {
			result[i][j] = 0;
		}
	}

//now do the actual math.........

	//triple nested loop? or to make a new function???????? new function would require learning how to pass this **matrix thing into a new function and id rather not do that
	int k;
	for (i = 0; i < firstRow; i++ ) {
		for ( j = 0; j < secCol; j++ ) {
			int sum = 0;
			for (k = 0; k < firstCol; k++) {
				sum += ((m1[i][k]) * (m2[k][j]));
			}
			result[i][j] = sum;
		}
	}

//print out mresukt
	for (i = 0; i < firstRow; i++) {
		for ( j = 0; j < secCol;j++ ) {
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}

