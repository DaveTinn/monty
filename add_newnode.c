#include "monty.h"
/**
 * add_Node - adds a new node to the head of the stack
 * @head: pointer to the top of the stack
 * @n: new value to be added to the stack
 * Return: Nothing
*/
void add_Node(stack_t **head, int n)
{

	stack_t *newNode, *currNode;

	currNode = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (currNode)
		currNode->prev = newNode;
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
