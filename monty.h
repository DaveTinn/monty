#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct global_s - a structure for global variables
 * @argmt: command line argumnent passed to the program
 * @my_file: pointer to FILE structure
 * @buff: to store data temporarily during input or output operations
 * @buff_index: an index within the buffer
 * Description: global variables structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	char *argmt;
	FILE *my_file;
	char *buff;
	int buff_index;
}  global_t;
extern global_t global_var;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

		/**	FUNCTIONS	**/
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *buff);
void my_push(stack_t **head, unsigned int number);
void my_pall(stack_t **head, unsigned int number);
void my_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int line_number, FILE *my_file);
void free_monty_stack(stack_t *head);
void my_pop(stack_t **head, unsigned int line_number);
void my_swap(stack_t **head, unsigned int line_number);
void my_add(stack_t **head, unsigned int line_number);
void my_nop(stack_t **head, unsigned int line_number);
void my_sub(stack_t **head, unsigned int line_number);
void my_div(stack_t **head, unsigned int line_number);
void my_mul(stack_t **head, unsigned int line_number);
void my_mod(stack_t **head, unsigned int line_number);
void my_pchar(stack_t **head, unsigned int line_number);
void my_pstr(stack_t **head, unsigned int line_number);
void my_rotl(stack_t **head, unsigned int line_number);
void my_rotr(stack_t **head, __attribute__((unused))unsigned int line_number);
void add_Node(stack_t **head, int n);
void addon_queue(stack_t **head, int n);
void my_queue(stack_t **head, unsigned int line_number);
void my_stack(stack_t **head, unsigned int line_number);
#endif
