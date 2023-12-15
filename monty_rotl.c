#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void my_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *head, *ax;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ax = (*head)->next;
	ax->prev = NULL;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *head;
	(*head)->next = NULL;
	(*head)->prev =curr;
	(*head) = ax;
}
