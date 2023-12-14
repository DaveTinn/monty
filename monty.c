#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 Always
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	input_file(argv[1], &stack);
	free_dlistint_t(stack);
	return (0);
}
