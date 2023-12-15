#include "monty.h"
/**
 * my_div - divides the second top element by the top element of the stack.
 * @head: pointer to the top of the stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_div(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len, ac;

	len = 0;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	ac = h->next->n / h->n;
	h->next->n = ac;
	*head = h->next;
	free(h);
}
