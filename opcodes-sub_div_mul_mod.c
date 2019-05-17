#include "monty.h"

/**
 * op_sub - subtracts the top element of the stack from the second top element
 * @stack: stack from which to manipulate elements
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_sub(stack_t **stack, unsigned int line_num)
{
	if (*stack && (*stack)->prev)
	{
		(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		fclose(world.input);
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
 * op_div - divides the second top element of stack by top element
 * @stack: stack from which to manipulate elements
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_div(stack_t **stack, unsigned int line_num)
{
	if (*stack && (*stack)->prev && (*stack)->n != 0)
	{
		(*stack)->prev->n = (*stack)->prev->n / (*stack)->n;
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
	}
	else
	{
		if (!(*stack)->prev)
			fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		else if ((*stack)->n == 0)
			fprintf(stderr, "L%u: division by zero\n", line_num);
		free_stack();
		fclose(world.input);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_mul - multiplies the second top element of stack with top element
 * @stack: stack from which to manipulate elements
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_mul(stack_t **stack, unsigned int line_num)
{
	if (*stack && (*stack)->prev)
	{
		(*stack)->prev->n = (*stack)->prev->n * (*stack)->n;
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		/* free element if it exists */
		exit(EXIT_FAILURE);
	}
}

/**
 * op_mod - computes modulo of second top element by top of stack
 * @stack: stack from which to manipulate elements
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_mod(stack_t **stack, unsigned int line_num)
{
	if (*stack && (*stack)->prev && (*stack)->n != 0)
	{
		(*stack)->prev->n = (*stack)->prev->n % (*stack)->n;
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		/* free element if it exists */
		exit(EXIT_FAILURE);
	}
}
