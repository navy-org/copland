#include "io.h"

void writer_puts(Writer *self, char const *s)
{
    while (*s)
    {
        self->putc(self, *s++);
    }
}

Writer writer_init(void (*putc)(Writer *, char))
{
    return (Writer) {
        .putc = putc,
        .puts = writer_puts
    };
}

Writer writer_init2(void (*putc)(Writer *, char), void (*puts)(Writer *, char const *))
{
    return (Writer) {
        .putc = putc,
        .puts = puts
    };
}