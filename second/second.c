#include <stdio.h>
#include <stdlib.h>

/*
 *linked list. read in a file in which there is 'i' or 'd' followed by a data value. if it says 'i' i must insert as long as there is no duplicate already. if there is, i will simply move on to the next. if it says 'd' then i must delete the node that holds the accompanying data value, as long as it exists within the LL. If at any time the file does not exist i should print "error" and nothing else. If the file is blank, then I should print "0\n". I really hate c.
 * 
 * This program's steps: 1) read the file. 2) check if it's i or d. 3) search thru the LL to see if the node exists. for i, if it already exists do nothing. for d, if it already exists delete. IF, i need to insert for i it must be inserted in order. As for delete, a simple deletion method ought to work. 4) at the end, print the list out as values on a single line, each separated by a tab.
 *
 * I will need: an insert function. a delete function. a print function. and possible a search function, but i might hard code that directly into the main method.
 */

struct listnode {
	int value;
	struct listnode* next;
};

void delete (struct listnode**, int);
int search (struct listnode*, int);
void insert (struct listnode**, struct listnode*);
void traverse (struct listnode*);
int length (struct listnode*);

int length(struct listnode* head) {
	int count =0;
	struct listnode* t1 = head;
	if (head == NULL) return 0 ;

	while (t1 != NULL) {
		count++;
		t1 = t1->next;
	}

//	printf("%d\n", count);
	return count;
			
}

void traverse (struct listnode* head) {
	struct listnode* t1 = head;
	
	if (head == NULL) printf("0\n");
	
	while (t1 != NULL) {
		printf("%d\t", t1->value);
		t1 = t1->next;
	}

	return;
}


struct listnode* newNode( int val) {
	struct listnode* temp = (struct listnode*) malloc(1*sizeof(struct listnode));
                        temp->value = val;
                        temp->next = NULL;
                        //head = NULL;
	return temp;
};

//welcome to deleteville muhahahaha

void delete (struct listnode** head, int val) {
//ok so this is going to be the same as my old java code too. there are three instances: if it's head, if it's in the middle, or if it's all the way at the end. and also if it just doesn't exist but i dont know that until i traverse thru the whole thing.

	struct listnode* temp = *head, *prev; //initialize the head and the pointer to go thru
	if (temp->value == val && temp != NULL) { //IF I FIND IT ALL THE WAY IN THE BEGINNING
		*head = temp->next;
		free(temp); //free up the space. do i have to do this for the assignment?
		return;
	}
	
	while (temp != NULL && temp->value != val) { //TRAVERSE MFFFFFF
		prev = temp; 
		temp = temp->next;
	}

	if (temp == NULL) return; //If it doesnt exist but i already know it does

	prev->next = temp->next; //my favorite part..... removing it from the equation all together
	free(temp); //free up the space.}
}


void insert (struct listnode** head, struct listnode* newNode) {
	
	//this is to insert in a sorted way, constantly maintaining the nodes from smallest to largest. there are three cases: insertion at beginning in which case the node becomes the head, insertion in the middle in which case you have to point the node to the next one and THEN point the previous to that node instead of the previous, and insertion at the end in which case next = NULL. port over the code that i wrote in DS for this one. 
	// in C, use -> instead of . to refer to objects (idk what objects r called in C bc it's not an object oriented language right)
	struct listnode* current; //declare the node to traverse with. ptr </3
	
	if ( *head == NULL || (*head)->value  > newNode->value) {//if the head is null, or if the new node's data is smaller than the head's node
		newNode->next = *head;
		*head = newNode; 
	} else {
		current = *head;
		//traverse thruuuuuuuuuu
		while (current->next != NULL && current->next->value < newNode->value) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}



int search (struct listnode* head, int key) {
		//search for a value. if found, return 1. if not found, return 0.
	struct listnode* current = head;
	while (current != NULL) {
		if (current -> value == key) {
		return 1;
		}
		current = current->next;
	}
	return 0;
}

int main (int argc, char** argv) {

	int data; char type; int sResult;

	if (argc != 2) { 
		printf("not enough arguments\n");
		return 0;
	}

	FILE *fp;
	fp = fopen(argv[1], "r");
	
	if (fp == NULL) { //if file doesn't exist, output "error"
		printf("error");
		return 0;
	}

	//DECLARE HEAD TO NEW LINKED LIST THAT IS EMPTY
	struct listnode *head = NULL;

	while (fscanf(fp, "%c %d\n", &type, &data) == 2) {

		if (type == 'i' ) {
		
			//run a search to see if this value already exists in the linked list. if it does, return 1. it it does not, return 0. 
			//if search returns true, go through with the following code:
			sResult = search(head, data);
			if (sResult == 0) {
				struct listnode* temp = newNode(data);
				//call insert here
				insert(&head, temp);
			} //SO HOW DO I MAKE IT DO NOTHING IF THE RESULT IS 1?
		
		} else if (type == 'd' ) {
			//I'm going to run a search like i did in insert. BUT, in this case, i only modify if it returns 1.
			//if it returns 1, i will delete said node. 
			sResult = search(head, data);
			if (sResult == 1) { //meaning it has been found
				//DELETE THE NODE WITH THE VALUE
				//i think the deletion method was the most difficult method? i just really dont remember
				delete(&head, data);
			}
			

		} 

}		

fclose(fp);
	

//PRINT OUT TO SCREEN
if (length(head) != 0 )
	printf("%d\n", length(head));

traverse(head);
printf("\n");
//fclose(fp);
return 0;
}
