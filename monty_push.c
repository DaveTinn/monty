#include "monty.h"
/**
 * my_push - adds a new node to the stack
 * @head: pointer to the head of the stack
 * @line_number: line number where the opcode occurs
 * Return: Nothing
*/
void my_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (global_var.argmt)
	{
		if (global_var.argmt[0] == '-')
			j++;
		for (; global_var.argmt[j] != '\0'; j++)
		{
			if (global_var.argmt[j] > 57 || global_var.argmt[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global_var.my_file);
			free(global_var.buff);
			free_monty_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(global_var.my_file);
		free(global_var.buff);
		free_monty_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(global_var.argmt);
	if (global_var.buff_index == 0)
		add_Node(head, n);
	else
		addon_queue(head, n);
}
