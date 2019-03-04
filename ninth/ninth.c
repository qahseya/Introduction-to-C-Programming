#include<stdio.h>
#include<stdlib.h>

/*
 * this program codes a binary search tree, which is essentially a tree in which the value of every leaf is greater than all the values of the leaves to the left of it and smaller than all the values to the right of it. this is also just a slightly more complicated linked list. i will try to re interpret the code that i have written in java to understand this better and maybe port over parts of it if there is no issue with the memory stuff. 
 *
 * i need to input nodes in their proper places and search for them as well. so that means i must know how to traverse and allocate for a new node every time. REMEMBER: INSERTIONS ON A BST ARE ALWAYS AT THE LEAF. I also need to return the height of the BST, basically a method for this that traverses a little differently
 *
 * 1. new node method
 * 2. insert method
 * 3. search  method
 * 4. height method that is just a traversal method that increments.
 *
 */

struct node {
	int data; 
	struct node* left;
	struct node* right;

};
struct node* newNode(int);
int compareTo(int, int);
struct node* search (struct node*, int); 
struct node* insert(struct node*, int);
int height(struct node*, int, int);
struct node* delete(struct node*, int);
struct node* min(struct node*); 

struct node* min(struct node* node) {
	//the minimum will always be the bottom of the left most subtree of every node. keep traveling left until the next node from the left is NULL.
	if (node->left == NULL) {
	return node;
	}
	return min(node->left);

}
struct node* delete (struct node* node, int target) {
//add the delete on here
/* delete has three instances: when the node u want to delete is the root, if it's something in the middile, if it has no children, or if it has only one child. in all of these u have to restructure the BST to accomodate these instances. theyre all very annoying.
 *
 */
//ok so the first step is to traverse thru the whole thing. use my search method logic here but call delete instead. as soon as i find the node's value, i will jump into the options: if it has no children, is root, or if it has one child (right or left will be separate instances) and if it has two children (in which i'll have to replace it with the SMALLEST value right after it, basically traversing down its left subtree)

	if (node == NULL){

		return NULL; //empty
	} else if (target < node->data) {
		node->left = delete(node->left, target);
	} else if (target > node->data) {
		node->right = delete(node->right, target);
	} else { //ive finished traversing
		if (node ->left == NULL && node->right == NULL) {
			node = NULL;
		} else if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		} else { //this is the one with two kids

		//malloc this ish??????
		struct node* temp = min(node->right);
		node->data = temp->data;
		node->right = delete(node->right, temp->data);
		}	

	}	
return node;
}

int height(struct node* head, int data, int heights) {
	/*
 * the issue with the original method is that it returns the height of the tree.... not the height of the node.
 * to find the height of the node: there must the base case of whether there's no node in the tree from before. if it's the first node, i'm just gonna set it to 1. and then i'm going to recrusviely go through the tree until i find a value that matches that value. everytime i reurse, i'm going to increase the height by 1. at the end, this is what i will return
 *
 */

	if (head == NULL) return 0;
	if ((head->data) == data) return heights;
	//^my base cases
	
	int depth = height((head->left), data, (heights+1));
	if (depth != 0) return depth;
	
	return height(head->right, data, heights+1);
	//this method is WRONG
/*	//BASE CASE IS ALWAYS THE NULL CASE
	if (head == NULL){  
 	      return 0; 
   	
	}else{ 
       //JUST RECURSIVELY GO RIGHT AND THEN LEFT AND U WILL GET THE HEIGHTS OF BOTH SUBTREES. USE THE CODE FOR TRAVERSAL OF A LL 
       //HEIGHT(NODE'S CHILLUN TO THE RIGHT
       //HEIGHT(NODE'S CHILLUN TO THE LEFT
       //COMPARE THE TWO AND SEE WHICH ONE IS BIGGER AND THEN ADD 1 TO IT TO INCLUDE THE ROOT	
        int heightRight = height(head->right);
	int heightLeft = height(head->left);


       if (heightLeft > heightRight)  

           return(heightLeft+1); 

       else return(heightRight+1); 
   } 
*/
}

struct node* newNode(int key) {
	//allocate memory
	struct node *new = (struct node*) malloc (sizeof(struct node));
	new->data = key;
	new->right = NULL;
	new->left = NULL;
	return new;
}

int compareTo(int key, int ptrKey) {

	if (key == ptrKey)
		return 5;

	if (key < ptrKey)
		return -1;

	if (key > ptrKey)
		return 1;

return 0;
}

struct node* search( struct node* root, int value) {
/*
 *my earlier method is not working bc it's not recursing through properly. i'm going to be returning a node. if it's NULL, that meeans that it was not found--> in which case for i: i will insert and print inserted and for s: i will print absent. or else, in the main method, i will compare the value of the node that was returned (stored in a node temp) and if it equals the data im trying to insert then i will print duplicate or present. otherwise i will insert
 */
	if( root == NULL) {
		return NULL;
	}

	if ((root->data) == value ) {
		return root;
	}
	
	if ((root->data) > value) {
		return search(root->left, value);
	}
	return search (root->right, value);

	/*if (root == NULL) 
		return 0;

	int key = root->data; 
	int c = 0; //this is for hte compare to method
	//do i have to create a pointer to do this?????
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	ptr = root;
	while (ptr != NULL) {
		c = compareTo(key, ptr->data);
		if (c==5){ //if theyre the same
	//	printf("present");
		return 1;


		}else if (c < 0 ) {
		  ptr = ptr->left;
	
		}else{
	
		 ptr = ptr->right;
		
		}
	}
//	printf("absent");

	return 0;
*/
}


struct node * insert(struct node * node, int key) {
	//base case
	//i may need to fix this base case for the duplicate instance because it's gonna return backwards thru recursion in the last if statement i made
	if (node == NULL) {
		return newNode(key);
//		printf("inserted");
//		return node;
	}

	//if it's smaller than the node that i'm at im gonna go left otherwise im gonna go right
	if (key < node->data) {
		node->left = insert(node->left, key);
	} else if (key > node->data ) {
		node->right = insert(node->right, key);
	} 
//	else if ( key == node->data) {
//		printf("duplicate");
//		return NULL;
//	}
	return node;
}

int main (int argc, char** argv) {
	int data; char type; int heights = 0; 	
	if (argc != 2) {
		printf("not enough arguments\n");
		return 0;
	}

	FILE *fp;
	
	fp = fopen(argv[1], "r");

	if (fp == NULL) {
		printf("error");
		return 0;
	}

	struct node *root = NULL; //int sResult = 0;
	
	while(fscanf(fp, "%c %d\n", &type, &data) == 2) {
		struct node *temp = (struct node*) malloc (sizeof(struct node));		
		if (type == 'i' ) {
			//struct node *temp = (struct node*) malloc (sizeof(struct node));
			//this is where my seg fault is happening. i'm calling for data of root, which is null. most of the time seg fault happens when i do null->next without 
			//i dont want to return 
			temp = search(root, data);
			if (temp == NULL) {
				//struct listnode* new =  newNode(data);
				root = insert(root, data);
				printf("inserted ");
				heights = height(root, data, 1);
				printf("%d\n", heights);
				//PRINT THE FREAKING HEIGHT

			} else if ((temp->data) == data) {
				printf("duplicate\n");
			}

		} else if (type == 's') {
			temp = search(root, data);

			if ((temp != NULL) && (temp->data ==  data)) {
				printf("present ");
				heights = height(root, data, 1);
				printf("%d\n", heights);
				//PRINT THE FREAKING HEIGHT
			} else {
				printf("absent\n");
			}			

		} else if (type == 'd') {
			temp = search(root, data);
			if ((temp != NULL) && (temp->data == data)) {
				printf("success\n");
				root = delete(root, data);
			} else {
				printf("fail\n");
			}
			
		}


	}
fclose(fp);

return 0;
}

