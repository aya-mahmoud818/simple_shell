#include "main.h"

int main (int argc, char **argv)
{
	char *prompt = "simpleshell $";
	size_t n = 0;
	char *line;

	(void)argc;
	(void)argv;

	printf("%s", prompt);
	getline(&line, &n, stdin);
	printf("%s\n", line);

	free(line);
	return (0);
}
