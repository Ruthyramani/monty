#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - representation of a queue
 * @n: integer
 * @prev: points the formal element of the queue
 * @next: points to the next element of a queue
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globe_s - global resources
 * @file: the file to run the monty instructuons from
 * @head: the stack
 * @line: line buffer
 * @line_no: current exec line number
 * @token_list: list of token
 *
 * Description: holds the line buffer for the prgram
 */
typedef struct globe_s
{
	struct stack_s *head;
	FILE *file;
	char *line;
	unsigned int line_no;
	char **token_list;
} globe_t;

extern globe_t *global;

/**
 * struct instruction_s - opcode and its functions
 * @opcode: the opcode
 * @f: function to the handle opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO , FIFO
 *
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(const int);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void divide(stack_t **, unsigned int);
int interprete(char **, unsigned int);
void allocate_memory(void);
void free_stack(void);
void free_memory(void);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif
