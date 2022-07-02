#pragma once 

#include "fmt.h"

#include <stddef.h>

#define __FILENAME__                                                                               \
    (__builtin_strrchr(__FILE__, '/') ? __builtin_strchr(__FILE__, '/') + 1 : __FILE__)

#define log$(FORMAT, ...) \
	log_impl(__FILENAME__, __LINE__, FORMAT, PRINT_ARGS(__VA_ARGS__));

#define panic$(FORMAT, ...) \
	panic_impl(__FILENAME__, __LINE__, FORMAT, PRINT_ARGS(__VA_ARGS__));

void log_impl(char const *filename, size_t line_nbr, char const *format, FmtArgs args);
void panic_impl(char const *filename, size_t line_nbr, char const *format, FmtArgs args);
void define_debug_out(Writer *writer);
Writer *get_debug_out(void);
void define_dbg_func(void (*dbg)(void));
void raise_debug(void);