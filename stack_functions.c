#include "monty.h"
void _print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int d;
	(void)line_number;

	d = 0;
	while (temp)
	{
		d = temp->n;
		if (d == 0 || is_alpha(d) == 0)
			break;
		putchar(d);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * first_rot - rotates the top element of the stack to the bottom
 * @monty_stack: pointer to the head of the monty stack
 * @num: line number where the opcode occurs
 * Return: Nothing
 */
void first_rot(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int ax;

	ax = 0;
	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;
	ax = curr->n;
	while (curr->next)
	{
		curr = curr->next;
		curr->prev->n = curr->n;
	}
	curr->n = ax;
}
void second_rot(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int ax;

	ax = 0;
	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;
	while (curr->next)
		curr = curr->next;
	ax = curr->n;

	while (curr->prev)
	{
		curr = curr->prev;
		curr->next->n = curr->n;
	}
	curr->n = ax;
}
