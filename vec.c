#include "base.h"

#include <assert.h>
#include <stdlib.h>

void vec_expand_(char **data, size_t *length, size_t *capacity, int memsz)
{
    if (*length + 1 > *capacity)
    {
        void *ptr;
        size_t n = (*capacity == 0) ? 1 : *capacity << 1;
        ptr = realloc(*data, n * memsz);

        if (ptr != NULL)
        {
            panic$("Couldn't allocate memory");
        }

        *data = ptr;
        *capacity = n;
    }
}