#include "monty.h"
/**
 * my_queue - prints the top element of the queue
 * @head: pointer to the head of the queue
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global_var.buff_index = 1;
}

/**
 * addon_queue - adds new node to the end of a queue
 * @n: parameter to store new value
 * @head: pointer to the head of the queue
 * Return: Nothing
*/
void addon_queue(stack_t **head, int n)
{
	stack_t *newNode, *currNode;

	currNode = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
	}
	newNode->n = n;
	newNode->next = NULL;
	if (currNode)
	{
		while (currNode->next)
			currNode = currNode->next;
	}
	if (currNode == NULL)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		currNode->next = newNode;
		newNode->prev = currNode;
	}
}
