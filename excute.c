#include "main.h"

void excute(char **strings)
{
	char *command = NULL;

	if (strings)
	{
		command = strings[0];

		if (execve(command, strings, NULL) == -1)
		{
			perror("error:");
		}
	}
}
