#include "monty.h"
struct_t world;
/**
* free_stack - frees a stack
*
* Return: nothing
*/

void free_stack(void)
{
	stack_t *run;

	while (world.stack)
	{
		run = ((world.stack)->prev);
		free(world.stack);
		world.stack = run;
	}
}


/**
* add_node - adds a node to a stack
* @stack: stack to add node to
* @n: data to put into new node
*
* Return: address of node
*/

void add_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/* call free function if stack exists */
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = n;

	if (world.stack == NULL)
		new->prev = NULL;
	else
		new->prev = world.stack;
	world.stack = new;
}

/**
* remove_node - removes a node from top of stack
* @stack: stack from which to remove node
*
* Return: address of new top
*/

void remove_node(void)
{
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
}
