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
			fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_num);
			free_stack();
			fclose(world.input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
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



