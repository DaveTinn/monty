#include "monty.h"
/**
 * subtraction - returns the differance
 * @monty_stack: pointer to the top of the stack
 * @num: integer paramer to report error
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int subt = 0, idx = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: stack too short, cannot subtract\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp == NULL)
	{
		temp = temp->next;
		idx++;
	}
	if (stack == NULL || (*stack)->next == NULL || idx <= 1)
	{
		fprintf(stderr, "L%d: stack too short, cannot subtract\n", line_number);
		exit(EXIT_FAILURE);
	}
	subt = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = subt;
}

/**
 * multiplication - returns the multipliction
 * @monty_stack: pointer to the top of the stack
 * @num: integer paramer to report error
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int multiply;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: stack too short, cannot multiply\n", line_number);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		free(global_var.buff);
		exit(EXIT_FAILURE);
	}
	else
	{
		multiply = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= multiply;
	}
}

/**
 * division - returns the division
 * @monty_stack: pointer to the top of the stack
 * @num: integer paramer to report error
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int divide = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: stack too short, cannot div\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: divides by zero\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		divide = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= divide;
	}
}

/**
 * modulus - returns the remainder
 * @monty_stack: pointer to the top of the stack
 * @num: integer paramer to report error
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int modulus = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: stack too short, cannot mod\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: divides by zero\n", line_number);
		free(global_var.buff);
		fclose(global_var.our_file);
		free_dlistint_t(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		modulus = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= modulus;
	}
}
