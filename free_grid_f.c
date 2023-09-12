#include "simple_shell.h"

void free_grid_f(char **array)
{
        int size = 0;
        if (array == NULL)
                return;

        while (array[size] != NULL)
        {
                free(array[size]);
                array[size] = NULL;
                size++;
        }

        free(array);
}
