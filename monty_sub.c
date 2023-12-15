#include "monty.h"
/**
 * my_sub- subtracts the top element of the stack from the second top element
 * @head: pointer to the head of the monty stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
 */
void my_sub(stack_t **head, unsigned int line_number)
{
	stack_t *newNode;
	int ac, itr;

	newNode = *head;
	for (itr = 0; newNode != NULL; itr++)
		newNode = newNode->next;
	if (itr < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	newNode = *head;
	ac = newNode->next->n - newNode->n;
	newNode->next->n = ac;
	*head = newNode->next;
	free(newNode);
}
