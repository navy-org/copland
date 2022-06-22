#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct 
{
    uintptr_t base;
    size_t length;
} Range;

#define range_end$(r) ((r).base + (r).length)