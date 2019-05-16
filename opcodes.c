#include "monty.h"
struct_t world;
/**
* get_op - calls the correct function
* @commands: array of commands
* @stack: stack to manipulate
* @line_number: current line number in program
*
* Return: 0
*/

int get_op(stack_t **stack, unsigned int line_number)
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
	int i;

	for (i = 0; known_instructions[i].opcode; i++)
	{
		if (strcmp(world.commands[0], known_instructions[i].opcode) == 0)
		{
			known_instructions[i].f(stack, line_number);
			return (0);
		}
	}
	{
		fprintf(stderr, "L%d: unknown instruction %s",
			line_number, world.commands[0]);
		/* free stack elements if they exist */
		exit(EXIT_FAILURE);
	}
	return (0);
}

