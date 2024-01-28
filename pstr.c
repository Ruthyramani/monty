#include "monty.h"

/**
 * pstr - opcode; prints string from climax of stack
 * @stack: pointer
 * @line_number: line no
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (((tmp)->n) < 128)
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
