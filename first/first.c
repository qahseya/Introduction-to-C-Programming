#include <stdio.h>
#include <stdlib.h>
/*
 * There are essentially 6 components of this problem: 1. reading the file. 2. Allocating enough memory based on the first number of the file. 3. Read the consecutive numbers, stored in a string, into ints. Remember there are negative numbers too. 4.Insert all even numbers athe beginning and all odd numbers at the end, and maintain a counter for the even numbers. 5. Call the swap function (based on the code in class, using POINTERS) on the even part, and the odd part. Either hard code comparisons into the swap function, or do the comparisions in main and then swapbased on that. 6. Print out the subsequent array using a for loop. 
*/

int main (int argc, char** argv);
void swap(int *, int *);
void selectionSort(int[], int, int);
//put the void prototype here
void selectionSort(int arr[], int beg, int length){
	int i; int j; int minIndex; int arrLength = length;

	for ( i = beg; i < arrLength; i++) {
		minIndex = i;
		for (j = i+1; j < arrLength; j++) 
			if (arr[j] < arr[minIndex])
				minIndex = j;

				swap(&arr[minIndex], &arr[i]);

	}
}
void swap( int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main( int argc, char** argv) {

	if (argc != 2) {
		printf("not enough arguments \n");
		return 0;
	}

	FILE *fp; //set the file pointer
	int curr; //ints to read the current one, and get the arrlength from the first line
	int arrLength; //this will read the first line of the file and store the int which is the number of indices in the array.
	fp = fopen(argv[1], "r"); //open and take in the name of the file
	//THIS WORKS!!!! printf("this should be the name of the file %s\n", argv[1]);
	if (fp == NULL) return 0;

	
	fscanf(fp,"%d\n", &curr); //the fp is the name of the file. arrlength would be the first int
	arrLength=curr;
//	printf("this should be the first line of the file, the array length: %d\n", arrLength);
	int *arr; //create an arry pointer

	arr = (int*)malloc(arrLength*sizeof(int)); //allocate space in memory
	int even = 0;
	int odd = (arrLength-1);
	int i;
//	int allSame;
	for ( i = 0; i < arrLength; i++){
		fscanf( fp, "%d", &curr);
//		printf("this should store every element of the array in the for loop: %d\n", curr);
		if (curr%2 == 0) {
			 arr[even]= curr;
			even++;	
		} else if (curr%2 != 0) {
			 arr[odd]=curr;
			 odd--;
		}		
}

int last = arrLength-1; int firstO;
//int lastE;

//check to see if they're all even or all odd. all even: the last indice will be even. all odd: the first indice will be odd

if ((arr[0]%2 != 0) || (arr[last]%2 == 0)) {
	selectionSort(arr, arr[0], arrLength);

}else {

	for (i = 0; i < arrLength; i++) {
		if (arr[i]%2 != 0) { //as soon as you find the first odd
		firstO = i;
		//lastE = i-1;
		break;
		}
	}
	//run selection sort on the even bits, the beginning of the array
	selectionSort(arr, 0, firstO); //array, where it begins, and the length
	selectionSort(arr, firstO, arrLength);
		
	//run selection sort on the odd bits, the end of the array

}
//WHY IS THIS NOT WORKING? 
////CALL SWAP HERE. first look at even. use selection sort. call swap to swap.
//	int b;
/*	int d; int firstOdd; int lastEven;
	for (d = 0; d < arrLength; d++) {
		int indice = arr[d];
		int index = d;
		int last = arrLength-1;
		//if the array is only evens or only odds, just run selection sort on the whole thing
		if (((indice%2 != 0) && (index == 0)) ||((arr[last] == indice) && (indice%2 == 0))){
			allSame = 1;
			break;
		}else if(indice%2 != 0){
			lastEven = index-1;
			firstOdd = index;		
		}							
	}

	int beg = 0;
	if (allSame == 1) { //if theyre all odd or all even:
		
		selectionSort(arr, beg, arrLength); 

	} else {
	
		selectionSort(arr, beg, lastEven);
		selectionSort(arr, firstOdd, arrLength); 
	}
*/
//ALL EVEN OR ALL ODD	 
		
/*
 	int b;
	for ( b = 0; b < even; b++) {
		int compareEven = arr[b]; int c;
		for ( c = b+1; c < even; c++) {
			if (arr[c] > arr[compareEven])
			swap(&c, &compareEven);
		}	
	}
	int t;
	for ( t = odd; t < arrLength; t++) {
		int compareOdd = arr[t];
		int v;
		for (v = t+1; v < odd; v++) {
			if (arr[v] > arr[compareOdd])
			swap(&v, &compareOdd); //REMOVED THE * POINTERS BECAUSE OF MAKEFILE COMPLAINT
		}	
	}	
*/
//PRINT IT OUT
	int j;
	for ( j = 0; j < arrLength; j++) {
		int element = arr[j];
		printf("%d\t", element);
	}

	fclose(fp);
	return 0;	
}



