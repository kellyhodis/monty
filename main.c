#include "monty.h"
#include <string.h>
/**
* read - open file and read content into a buffer
* @input_file: filename
* @buffer: to read the contents of file
*
* Return: pointer to buffer
*/

char *read(FILE *input_file, char *buffer)
{
	size_t length = 1024, i;

	buffer = malloc(length);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length; i++)
		buffer[i] = '\0';

	fread(buffer, length, 1, input_file);
	printf("%s\n", buffer);
	printf("\nthis is just for now\n");
	return (buffer);
}

/**
* parse_buffer - parse buffer into lines
* @buffer: buffer to parse
* @instructions: array to store lines
*
* Return: 0 if success or line number if failure
*/

char *parse_buffer(char *buffer, char *instructions[])
{
	char *token;
	int i;

	token = strtok(buffer, "\n");
	for (i = 0; token; i++)
	{
		instructions[i] = strdup(token);
		token = strtok(NULL, "\n");
	}
	instructions[i] = NULL;
	return (instructions[0]);
}

/**
* parse_instructions - parse lines of buffer into commands with arguments
* @instruction: line to parse
* @commands: array to store commands with arguments
*
* Return: pointer to the first command
*/

char *parse_instructions(char *instruction, char *commands[])
{
	char *token;
	int j;

	if (instruction)
	{
		token = strtok(instruction, " ");
		for (j = 0; token; j++)
		{
			commands[j] = token;
			token = strtok(NULL, " ");
		}
		commands[j] = NULL;
	}
	return (commands[0]);
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
	char *instructions[25], *commands[30];
	int i, j;

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
		buffer = read(input, buffer);
		printf("%s\nthis is the buffer in main\n", buffer);
		instructions[0] = parse_buffer(buffer, instructions);
		for (i = 0; instructions[i]; i++)
		{
			commands[0] = parse_instructions(instructions[i], commands);
			/* call opcode function */
			for (j = 0; commands[j]; j++)
				printf("%s\n", commands[j]);
		}
		for (i = 0; instructions[i]; i++)
			printf("%s\n", instructions[i]);
		for (i = 0; commands[i]; i++)
			printf("%s\n", commands[i]);
	}
	for (i = 0; instructions[i]; i++)
		free(instructions[i]);
	free(buffer);
	fclose(input);
	return (0);
}
