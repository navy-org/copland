#include "io.h"
#include <stddef.h>

void writer_puts(Writer *self, char const *s)
{
    while (*s)
    {
        self->putc(self, *s++);
    }
}

Writer writer_init_impl(void (*putc)(Writer *, char), void (*puts)(Writer *, const char *))
{
    return (Writer) {
        .putc = putc,
        .puts = puts == NULL ? writer_puts : puts
    };
}