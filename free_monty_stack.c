#include "monty.h"
/**
* free_monty_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_monty_stack(stack_t *head)
{
	stack_t *newNode;

	newNode = head;
	while (head)
	{
		newNode = head->next;
		free(head);
		head = newNode;
	}
}
