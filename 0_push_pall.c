#include "monty.h"
void push_stk(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failure\n");
		exit(EXIT_FAILURE);
	}
	top->n = global_var.push_element;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = top;
	*stack = top;
	}
}
void pall_stk(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *handler;

	handler = *stack;
	while (handler != NULL)
	{
		printf("%d\n", handler->n);
		handler = handler->next;
	}
}
void pint_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *handler;

	handler = *stack;
	if (handler == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", handler->n);
}
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *handler;

	handler = *stack;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = handler->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(handler);
}
void free_dlistint_t(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		head = temp;
		free(head);
	}
}
