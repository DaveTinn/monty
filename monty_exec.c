#include "monty.h"
/**
 * execute - executes an opcode
 * @buff: stores data during input/output operations
 * @stack: head of a linked list(stack)
 * @file: poiner to monty file
 * @line_number: line number where the opcode occurs
 * Return: Nothing
 */
int execute(char *buff, stack_t **stack,
		unsigned int line_number, FILE *my_file)
{
	instruction_t _opCode[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{"sub", my_sub},
		{"div", my_div},
		{"mul", my_mul},
		{"mod", my_mod},
		{"pchar", my_pchar},
		{"pstr", my_pstr},
		{"rotl", my_rotl},
		{"rotr", my_rotr},
		{"queue", my_queue},
		{"stack", my_stack},
		{NULL, NULL}
	};
	unsigned int itr = 0;
	char *str;

	str = strtok(buff, " \n\t");
	if (str && str[0] == '#')
		return (0);
	global_var.argmt = strtok(NULL, " \n\t");
	while (_opCode[itr].opcode && str)
	{
		if (strcmp(str, _opCode[itr].opcode) == 0)
		{	_opCode[itr].f(stack, line_number);
			return (0);
		}
		itr++;
	}
	if (str && _opCode[itr].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
		fclose(my_file);
		free(buff);
		free_monty_stack(*stack);

		exit(EXIT_FAILURE);
	}
	return (1);
}
