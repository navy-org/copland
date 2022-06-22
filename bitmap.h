#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "range.h"

typedef struct 
{
    union  
    {
        struct 
        {
            uint8_t *buffer;
            size_t length;
        };

        Range range;
    };
} Bitmap;

void bitmap_set_bit(Bitmap *self, size_t index);
void bitmap_clear_bit(Bitmap *self, size_t index);
bool bitmap_is_bit_set(Bitmap *self, size_t index);
void bitmap_fill(Bitmap *self, uint8_t byte);