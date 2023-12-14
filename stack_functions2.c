#include "monty.h"
/**
 * swap - swap top of stack with second top stack
 * @stack: pointer to head of the monty stack
 * @line_number: line number where the opcode occurs
 *
 * Return: Nothing
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int temp;

	curr = *stack;
	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = temp;
}

/**
 * add - add top of stack with second top stack
 * @stack: pointer to head of the monty stack
 * @line_number: line number where the opcode occurs
 *
 * Return: Nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0, idx = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		idx++;
	}

	if (stack == NULL || (*stack)->next == NULL || idx <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * nop - nop top of stack by second top stack
 * @stack: pointer to head of the monty stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
 */

void _nop(__attribute__ ((unused))stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the monty stack
 * @line_number: the index of the current line
 *
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * is_alpha - checks for alphabet
 * @d: integer data type
 *
 * Return: 1 if yes, else 0
 */
int is_alpha(int d)
{
	if ((d >= 97 && d <= 122) || (d >= 65 && d <= 90))
		return (1);
	else
		return (0);
}
