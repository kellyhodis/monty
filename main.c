#include "monty.h"
struct_t world;

/**
* read - open file and read content into a buffer
* @input: filename
* @buffer: to read the contents of file
*
* Return: pointer to line
*/

void read(FILE *input, char *buffer)
{
	size_t i, length = 0;
	char *token;
	int line_num = 0, line_length = 0;
	stack_t *stack = NULL;

	line_length = getline(&buffer, &length, input);
	while (line_length >= 0)
	{
		token = strtok(buffer, "\n\t ");
		for (i = 0; token; i++)
		{
			world.commands[i] = token;
			token = strtok(NULL, "\n\t ");
		}
		world.commands[i] = NULL;
		line_num++;
		get_op(&stack, line_num);
		free(buffer);
		buffer = NULL;
		line_length = getline(&buffer, &length, input);
	}
}

/**
* main - an interpreter for Monty ByteCodes files
* @argc: argument count
* @argv: argument vector
*
* Return: 0
*/

int main(int argc, char **argv)
{
	FILE *input;
	char *buffer = NULL;
	int i;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 1)
	{
		input = fopen(argv[1], "rb");
		if (!input)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < 15; i++)
			world.commands[i] = NULL;
		read(input, buffer);
	}
	fclose(input);
	return (0);
}
