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
	int hold;

	(void)stack;
	if ((world.stack) && (world.stack)->prev)
	{
		hold = (world.stack)->n;
		(world.stack)->n = (world.stack)->prev->n;
		(world.stack)->prev->n = hold;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(world.input);
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
* op_add - adds the top two elements of the stack
* @stack: stack to add elements of
* @line_number: current line number of program
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
