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


