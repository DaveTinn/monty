#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int push_element;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - definining the opcode with the function
 * @our_file: the opcode file
 * @push_element: parameter of ineger data type to handle the opcode
 * @buff: parameter of char data type for storing the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	FILE *our_file;
	int push_element;
	char *buff;
}
global_t;

extern global_t global_var;
typedef void (*command_funct)(stack_t **stack, unsigned int line_number);

void _mod(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void input_file(char *filename, stack_t **head);
int is_integer(char *str);
command_funct get_opFunction(char *str);
char parse_String(char *str, stack_t **stack, unsigned int line_number);
void push_stk(stack_t **stack, __attribute__ ((unused)) unsigned int line_number);
void pall_stk(stack_t **stack, __attribute__ ((unused)) unsigned int line_number);
void pint_stack(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void free_dlistint_t(stack_t *head);
void _print_str(stack_t **stack, unsigned int line_number);
void first_rot(stack_t **stack, unsigned int line_number);
void second_rot(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
int is_alpha(int d);
void _pchar(stack_t **stack, unsigned int line_number);
void _nop(__attribute__ ((unused))stack_t **stack, __attribute__ ((unused)) unsigned int line_number);
#endif
