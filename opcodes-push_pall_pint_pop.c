#include "monty.h"

/**
* op_push - pushes an element to the stack
* @stack: stack to push element to
* @line_number: current line of program
*
* Return: integer of some sort
*/

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		/* error message for malloc */
	}

	new->next = NULL;
	new->n = line_number;
	if (!*stack)
		new->prev = NULL;
	else
		new->prev = *stack;
	*stack = new;
}

/**
* op_pall - prints all values on the stack starting from top
* @stack: stack to print
* @line_number: line number in program
*
* Return: integer of some kind
*/

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *run;

	(void)line_number;
	run = *stack;
	while (run)
	{
		printf("%d\n", run->n);
		run = run->prev;
	}
}

/**
* op_pint - prints the value at the top of the stack
* @stack: stack to get value from
* @line_number: line number in program
*
* Return: nothing
*/

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		fprintf(stdout, "%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* op_pop - removes the top element of the stack
* @stack: stack to remove element from
* @line_number: line number in program
*
* Return: nothing
*/

void op_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (*stack->prev)
		{
			*stack = (*stack)->prev;
			free((*stack)->next);
		}
		else
			free(*stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}