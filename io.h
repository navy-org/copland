#pragma once 

#include "map.h"

typedef struct _Writer 
{
    void (*putc)(struct _Writer *self, char c);
    void (*puts)(struct _Writer *self, char const *s);
} Writer;

#define __writer_init_impl2(n, ...) writer_init ## n(__VA_ARGS__)
#define __writer_init_impl(n, ...)  __writer_init_impl2(n, __VA_ARGS__)
#define writer_init(...) __writer_init_impl(GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

void writer_puts(Writer *self, char const *s);
Writer writer_init1(void (*putc)(Writer *, char));
Writer writer_init2(void (*putc)(Writer *, char), void (*puts)(Writer *, char const *));