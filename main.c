#include "main.h"
/**
 * main -entery
 *
 * Return: 0
 */

int main(int argc, char **strings)
{
	char *prompt = "simpleshell $";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t size = 0;
	ssize_t num_chars;
	char *token;
	const char *delim = " \n";
	int i, num_tokens = 0;

	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		num_chars = getline(&lineptr, &size, stdin);

		if (num_chars == -1)
		{
			printf("Exit\n");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * num_chars);

		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}

		num_tokens++;

		strings = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			strings[i] = malloc(sizeof(char) * strlen(token));
			strcpy(strings[i], token);

			token = strtok(NULL, delim);
		}

		strings[i] = NULL;

		excute(strings);
	}

		free(lineptr);
		free(lineptr_copy);

	return (0);
}
