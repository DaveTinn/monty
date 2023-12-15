#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void my_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *currNode = *head, *newNode;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	newNode = (*head)->next;
	newNode->prev = NULL;
	while (currNode->next != NULL)
	{
		currNode = currNode->next;
	}
	currNode->next = *head;
	(*head)->next = NULL;
	(*head)->prev = currNode;
	(*head) = newNode;
}
