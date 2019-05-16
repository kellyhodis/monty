#include "monty.h"
struct_t world;
/**
* get_op - calls the correct function
* @line_number: current line number in program
*
* Return: 0
*/

int get_op(unsigned int line_number)
{
	instruction_t known[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{NULL, NULL}
	};
	int i;

	for (i = 0; known[i].opcode; i++)
	{
		if (strcmp(world.commands[0], "push") == 0 && world.commands[1] == NULL)
			world.commands[1] = "x";
		if (world.commands[0] && strcmp(world.commands[0], known[i].opcode) == 0)
		{
			known[i].f(&(world.stack), line_number);
			return (0);
		}
	}
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, world.commands[0]);
		free_stack();
		fclose(world.input);
		exit(EXIT_FAILURE);
	}
	return (0);
}

