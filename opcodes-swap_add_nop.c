#include "monty.h"

/**
* op_swap - swaps the top two elements of the stack
* @stack: stack to manipulate
* @line_number: current line number of program
*
* Return: nothing
*/

void op_swap(stack_t **stack, unsigned int line_number)
{
	if ((*stack) && (*stack)->prev)
	{
		/* swap elements */
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		/* free stack element if there was one */
		exit(EXIT_FAILURE);
	}
}

/**
* op_add - adds the top two elements of the stack
* @stack: stack to add elements of
* #line_number: current line number of program
*
* Return: nothing
*/

void op_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) && (*stack)->prev)
	{
		*stack = (*stack)->prev;
		(*stack)->n = (*stack)->n + (*stack)->next->n;
		free((*stack)->next);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		/* free stack element if there is one */
		exit(EXIT_FAILURE);
	}

}

/**
* op_nop - does nothing
* @stack: stack on which nothing is done
* @line_number: current line number of program
*
* Return: nothing
*/

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
