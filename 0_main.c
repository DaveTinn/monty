#include "monty.h"
#include <stdio.h>
global_t global_var = {NULL, NULL, NULL, 0};
/**
* main - Entry point
* @argc: number of command line arguments
* @argv: array of strings representing the command line arguments
* Return: 0 Always
*/
int main(int argc, char *argv[])
{
	char *buff;
	FILE *my_file;
	size_t size = 0;
	ssize_t input = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	my_file = fopen(argv[1], "r");
	global_var.my_file = my_file;
	if (!my_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (input > 0)
	{
		buff = NULL;
		input = getline(&buff, &size, my_file);
		global_var.buff = buff;
		line_number++;
		if (input > 0)
		{
			execute(buff, &stack, line_number, my_file);
		}
		free(buff);
	}
	free_monty_stack(stack);
	fclose(my_file);
	return (0);
}

