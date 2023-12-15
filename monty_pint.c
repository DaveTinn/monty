#include "monty.h"
/**
 * my_pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
