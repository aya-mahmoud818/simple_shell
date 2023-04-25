#include "main.h"
/**
 * select_loc -entery
 *
 * @command: command
 *
 * Return: 0
 */

char *select_loc(char *command)
{
	char *path, *cp_path, *path_tok, *file_path;
	int command_len, dir_len;
	struct stat buf;

	path = getenv("PATH");
	if (path)
	{
		cp_path = strdup(path);
		command_len = strlen(command);
		path_tok = strtok(cp_path, ":");
		while (path_tok != NULL)
		{
			dir_len = strlen(path_tok);
			file_path = malloc(command_len + dir_len + 2);

			strcpy(file_path, path_tok);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buf) == 0)
			{
				free(cp_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}
	free(cp_path);
	if (stat(command, &buf) == 0)
	{
		return (command);
	}
	return (NULL);
	}

	return (NULL);
}
