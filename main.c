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
	size_t i, length = 1024;
	char *token;
	int line_num = 0;
	ssize_t line_length = 0;

	world.stack = NULL;
	while ((line_length = getline(&buffer, &length, input)) != -1)
	{
		token = strtok(buffer, "\n\t\r\v\f ");
		line_num++;
		if (!token)
			continue;
		for (i = 0; token && i < 2; i++)
		{
			world.commands[i] = token;
			token = strtok(NULL, "\n\t\r\v\f ");
		}
		world.commands[i] = NULL;
		if (world.commands[0][0] == '#')
			continue;
		get_op(line_num);
		for (i = 0; i < 1024; i++)
			buffer[i] = '\0';
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
	char buffer[1024];
	int i;
	FILE *input;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 1)
	{
		input = fopen(argv[1], "r");
		if (input == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < 15; i++)
			world.commands[i] = NULL;
		world.input = input;
		for (i = 0; i < 1024; i++)
			buffer[i] = '\0';
		read(input, buffer);
		fclose(input);
		free_stack();
	}
	return (0);
}
