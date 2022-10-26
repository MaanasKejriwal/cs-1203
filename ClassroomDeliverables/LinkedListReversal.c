// Reversal of linked list that is given
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node* next;
};


static void reverse(struct Node** heads)
{
	struct Node* prev = NULL;
	struct Node* current = *heads;
	struct Node* next = NULL;
	while (current != NULL) {
		
		next = current->next;

		
		current->next = prev;

		
		prev = current;
		current = next;
	}
	*heads = prev;
}


void push(struct Node** heads, int datanew)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->val = datanew;
	new_node->next = (*heads);
	(*heads) = new_node;
}


void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->val);
		temp = temp->next;
	}
}


int main()
{
	
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Initial linked list\n");
	printList(head);
	reverse(&head);
	printf("\nReversed linked list \n");
	printList(head);
	getchar();
}
