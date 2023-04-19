#include "main.h"
/**
 * main -entery
 *
 * @argc: arguments count
 * @argv: vector
 *
 * Return: 0
 */

int main(void){
    char *prompt = "simpleshell $";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t num_chars; 
    char *token;
    const char *delim = " \n";
    char **argv;
    int i = 0; 
    int n_tokens = 0;

   
    printf("$ ");

    num_chars = getline(&lineptr, &n, stdin);

    lineptr_copy = malloc(sizeof(char) * num_chars);

    if (lineptr_copy == NULL){
        perror("tsh: memory allocation error");
        return (-1);
    }

    strcpy(lineptr_copy, lineptr);

    if (num_chars == -1){
        printf("Exiting shell...\n");
        return (-1);
    } else {

        token = strtok(lineptr, delim);

        while (token != NULL){
            n_tokens++;
            token = strtok(NULL, delim);
        }
        n_tokens++;

        argv = malloc(sizeof(char *) * n_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;



        free(argv);
        free(lineptr);
        free(lineptr_copy);
    }

    return (0);
}
