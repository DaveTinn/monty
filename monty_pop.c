#include "monty.h"
/**
 * my_pop - removes the top element from the stack
 * @head: pointer to the head of the stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
