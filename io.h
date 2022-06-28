#pragma once 

#include "map.h"

typedef struct _Writer 
{
    void (*putc)(struct _Writer *self, char c);
    void (*puts)(struct _Writer *self, char const *s);
} Writer;

Writer writer_init_impl(void (*putc)(Writer *, char), void (*puts)(Writer *, char const *));
#define __writer_init(putc, puts, ...) writer_init_impl(putc, puts)
#define writer_init(...) __writer_init(__VA_ARGS__, 0)