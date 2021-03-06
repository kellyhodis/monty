#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack with new line
 * @stack: stack
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_pchar(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	if (world.stack)
	{
		if (isalpha((world.stack)->n) != 0)
			printf("%c\n", (world.stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_num);
			free_stack();
			fclose(world.input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_num);
		free_stack();
		fclose(world.input);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pstr - prints the string starting at the top of the stack with new line
 * @stack: stack
 * @line_num: current line number in program
 *
 * Return: nothing
 */
void op_pstr(stack_t **stack, unsigned int line_num)
{
	char str[50];
	int i;
	stack_t *run;

	(void)stack;
	(void)line_num;
	for (i = 0; i < 50; i++)
		str[i] = '\0';
	run = world.stack;
	if (run)
	{
		for (i = 0; i < 50 && run; i++)
		{
			if (isalpha(run->n) != 0)
			{
				str[i] = run->n;
				run = run->prev;
			}
			else
				break;
		}
		printf("%s\n", str);
	}
	else
		printf("\n");
}

/**
 * op_rotl - rotates the stack to the top
 * @stack: stack
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *run, *hold;

	(void)stack;
	(void)line_num;

	if (world.stack && (world.stack)->prev)
	{
		hold = world.stack;
		run = (world.stack)->prev;
		while (hold->prev)
			hold = hold->prev;
		run->next->prev = NULL;
		hold->prev = run->next;
		hold->prev->next = hold;
		run->next = NULL;
		world.stack = run;
	}
}

/**
 * op_rotr - rotates stack to bottom
 * @stack: stack
 * @line_num: current line number in program
 *
 * Return: nothing
 */

void op_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *run, *hold;

	(void)stack;
	(void)line_num;

	if (world.stack && (world.stack)->prev)
	{
		hold = world.stack;
		run = world.stack;
		while (hold->prev)
			hold = hold->prev;
		hold->prev = run;
		hold->next->prev = NULL;
		hold->next = NULL;
		run->next = hold;
		world.stack = hold;
	}
}

