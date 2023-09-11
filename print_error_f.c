#include "simple_shell.h"

/**
 * print_error_f - prints an error message if couldn't allocate memory
*/
void print_error_f(void)
{
        perror("Error: Couldn't allocate memory\n");
        exit(EXIT_FAILURE);
}
