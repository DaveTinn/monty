#include "monty.h"
void input_file(char *filename, stack_t **stack)
{
	command_funct d;
	char *lin;
	size_t idx = 0;
	int l_count = 1;
	int inspect;
	int input;

	global_var.our_file = fopen(filename, "r");
	if (global_var.our_file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((input = getline(&global_var.buff, &idx, global_var.our_file)) != -1)
	{
		lin = parse_String(global_var.buff, stack, l_count);
		if (lin == NULL || lin[0] == '$')
		{
			l_count++;
			continue;
		}
		d = get_opFunction(lin);
		if (d == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l_count, lin);
			exit(EXIT_FAILURE);
		}
		d(stack, l_count);
		l_count++;
	}
	free(global_var.buff);
	inspect = fclose(global_var.our_file);
	if (inspect == -1)
		exit(-1);
}
command_funct get_opFunction(char *str)
{
	int j;

	instruction_t instruct[] = {
		{"push", push_stk},
		{"pall", pall_stk},
		{"pint", pint_stack},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _print_str},
		{"rotl", first_rot},
		{"rotr", second_rot},
		{NULL, NULL},
	};

	j = 0;
	while (instruct[j].f != NULL && strcmp(instruct[j].opcode, str) != 0)
	{
		j++;
	}
	return (instruct[j].f);
}
int is_integer(char *str)
{
	unsigned int j;

	if (str == NULL)
		return (0);
	j = 0;
	while (str[j])
	{
		if (str[0] == '-')
		{
			j++;
			continue;
		}
		if (!isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}
char parse_String(char *str, stack_t **stack, unsigned int line_number)
{
	char *_opCode, *argmt, *_push;
	(void)stack;

	_push = "push";
	_opCode = strtok(str, "\n");
	if (_opCode == NULL)
		return (NULL);

	if (strcmp(_opCode, _push) == 0)
	{
		argmt = strtok(NULL, "\n");
		if (is_integer(argmt) == 1 && argmt != NULL)
		{
			global_var.push_element = atoi(argmt);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (_opCode);
}
