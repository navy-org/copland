#include "base.h"

#ifdef __osdk_freestanding__
#include <kernel/spinlock.h>

static uint32_t lock;
#define lock() lock$(lock)
#define unlock() unlock$(lock)

#endif

static Writer *debugDevice = NULL;
static void (*dbg_fn)(void) = NULL;

void define_debug_out(Writer *writer)
{
    debugDevice = writer;
}

Writer *get_debug_out(void)
{
    return debugDevice;
}

void define_dbg_func(void (*dbg)(void))
{
    dbg_fn = dbg;
}

void log_impl(char const *filename, size_t line_nbr, char const *format, FmtArgs args)
{
    lock();

    fmt$(debugDevice, "\033[33m{}:{}\033[0m ", filename, line_nbr);
    fmt_impl(debugDevice, format, args);
    debugDevice->putc(debugDevice, '\n');

    unlock();
}

void panic_impl(char const *filename, size_t line_nbr, char const *format, FmtArgs args)
{
    fmt$(debugDevice, "\033[31m{}:{}\033[0m PANIC! ", filename, line_nbr);
    fmt_impl(debugDevice, format, args);
    debugDevice->putc(debugDevice, '\n');

    raise_debug();
}

void raise_debug(void)
{
    if (dbg_fn == NULL)
    {
        loop;
    } 
    else 
    {
        dbg_fn();
    }
}
