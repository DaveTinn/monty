#include "monty.h"
/**
 * my_add - sums top two elements on the stack.
 * @head: pointer to the top of the stack
 * @line_number: line number in the stack where the opcode occurs
 * Return: Nothing
*/
void my_add(stack_t **head, unsigned int line_number)
{
	stack_t *new_element;
	int len, ac;

	len = 0;
	new_element = *head;
	while (new_element)
	{
		new_element = new_element->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_element = *head;
	ac = new_element->n + new_element->next->n;
	new_element->next->n = ac;
	*head = new_element->next;
	free(new_element);
}
