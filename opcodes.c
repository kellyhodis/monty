#include "monty.h"

/**
* get_op - calls the correct function
* @commands: array of commands
* @stack: stack to manipulate
* @line_number: current line number in program
*
* Return: 0
*/

int get_op(char *commands[], stack_t **stack, unsigned int line_number)
{
	instruction_t known_instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	int i, j, num_arg;

	for (i = 0; known_instructions[i].opcode; i++)
	{
		if (strcmp(commands[0], known_instructions[0].opcode) == 0)
		{
			if (commands[1] && commands[1][0] > 47 && commands[1][0] < 58)
			{
				/* figure out a way to keep the info for command */
				for (j = 0; commands[1][j] > 47 && commands[1][j] < 58; j++)
					;
				commands[1][j] = '\0';
				num_arg = atoi(commands[1]);
				printf("argument: %d\n", num_arg);
				known_instructions[i].f(stack, line_number);
				return (0);
			}
		}
		if (strcmp(commands[0], known_instructions[i].opcode) == 0)
		{
			known_instructions[i].f(stack, line_number);
			return (0);
		}
	}
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, commands[0]);
		/* free stack elements if they exist */
		exit(EXIT_FAILURE);
	}
	return (0);
}

