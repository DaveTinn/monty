#include "monty.h"
/**
 * my_mul - multiplies the top two elements of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, ac;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ac = h->next->n * h->n;
	h->next->n = ac;
	*head = h->next;
	free(h);
}
