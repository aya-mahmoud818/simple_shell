#include "main.h"
/**
 * main -entery
 *
 * @argc: arguments count
 * @argv: vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt = "simpleshell $";
	size_t n = 0;
	char *line;
	ssize_t num_chars;

	(void)argc;
	(void)argv;

	while (1)
	{
	printf("%s", prompt);

	num_chars = getline(&line, &n, stdin);
	if (num_chars == -1)
	{
		printf("exit\n");
		return (-1);
	}

	printf("%s\n", line);

	free(line);
	}
	return (0);
}
