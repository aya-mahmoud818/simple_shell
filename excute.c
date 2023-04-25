#include "main.h"
/**
 * excute -entery
 *
 * @strings: strinngs
 *
 * Return: 0
 */

void excute(char **strings)
{
	char *command = NULL, *main_command = NULL;

	if (strings)
	{
		command = strings[0];
		main_command = select_loc(command);
		if (execve(main_command, strings, NULL) == -1)
		{
			perror("error:");
		}
	}
}
