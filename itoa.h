#pragma once

#include <stdint.h>
#include <stddef.h>

char *itoa(int64_t value, char *str, uint64_t base, size_t buf_size);