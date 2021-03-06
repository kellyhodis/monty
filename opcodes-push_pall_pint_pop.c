#include "monty.h"
struct_t world;

/**
 * exit_program - performs exiting functions
 *
 * Return: nothing
 */

void exit_program(void)
{
	free_stack();
	fclose(world.input);
	exit(EXIT_FAILURE);
}

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
	int i;

	(void)stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_program();
	}

	new->next = NULL;
	if (isdigit(world.commands[1][0]) == 0 && world.commands[1][0] != '-')
	{
		free(new);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_program();
	}
	for (i = 1; world.commands[1][i]; i++)
	{
		if (isdigit(world.commands[1][i]) == 0)
		{
			free(new);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit_program();
		}
	}
	new->n = atoi(world.commands[1]);
	if (!world.stack)
		new->prev = NULL;
	else
	{
		new->prev = world.stack;
		(world.stack)->next = new;
	}
	world.stack = new;
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

	(void)stack;
	(void)line_number;
	run = world.stack;
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
		fclose(world.input);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
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
	(void)stack;
	if (world.stack)
	{
		if ((world.stack)->prev)
		{
			world.stack = (world.stack)->prev;
			free((world.stack)->next);
			(world.stack)->next = NULL;
		}
		else
		{
			free(world.stack);
			world.stack = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(world.input);
		exit(EXIT_FAILURE);
	}
}
