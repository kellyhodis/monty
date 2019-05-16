#include "monty.h"
/**
* read_line - open file and read content into a buffer
* @input_file: filename
* @buffer: to read the contents of file
*
* Return: pointer to line
*/

void read(FILE *input, char *buffer, char *commands[])
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
			commands[i] = token;
			token = strtok(NULL, "\n\t ");
		}
		commands[i] = NULL;
		line_num++;
		get_op(commands, &stack, line_num);
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
	char *commands[30];

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

		read(input, buffer, commands);
	}
	fclose(input);
	return (0);
}
