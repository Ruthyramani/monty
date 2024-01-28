#include "monty.h"

/**
 * rotl - opcode; rotates the top element
 * @stack: pointer
 * @line_number: line number
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tm = *stack;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	tm->next = *stack;
	(*stack) = (*stack)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}
