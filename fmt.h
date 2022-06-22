#pragma once 

#include "range.h"
#include "str.h"
#include "io.h"

#include <stdint.h>
#include <stddef.h>

typedef enum 
{
    FMT_INT, 
    FMT_CHAR,
    FMT_STR,
    FMT_RANGE,
} FmtValueType;

typedef struct 
{
    FmtValueType type;

    union 
    {
        int64_t _int;
        char _char;
        char const *_str;
        Range _range;
    };
} FmtValue;

typedef struct 
{
    char const *fmt;
    size_t size;
    size_t offset;
} FmtParser;

typedef struct
{
    size_t count;
    FmtValue *values;
} FmtArgs;

static inline FmtValue fmtvali(int64_t val)
{
    return (FmtValue) {
        .type = FMT_INT,
        ._int = val
    };
}

static inline FmtValue fmtvalcs(char const *val)
{
    return (FmtValue) {
        .type = FMT_STR,
        ._str = val
    };
}

static inline FmtValue fmtvalc(char val)
{
    return (FmtValue) {
        .type = FMT_CHAR,
        ._char = val
    };
}

static inline FmtValue fmtvalr(Range val)
{
    return (FmtValue) {
        .type = FMT_RANGE,
        ._range = val
    };
}

static inline FmtValue fmtvals(Str str)
{
    return (FmtValue) {
        .type = FMT_STR,
        ._str = str.buf
    };
}

#define SELECT_VALUE(__value) _Generic (                \
    (__value),                                          \
    int: fmtvali,                                       \
    size_t: fmtvali,                                    \
    char const *: fmtvalcs,                             \
    char *: fmtvalcs,                                   \
    char: fmtvalc,                                      \
    Range: fmtvalr,                                     \
    Str: fmtvals                                        \
)(__value),

#define PRINT_ARGS_(...)                                                                           \
    (FmtArgs)                                                                                      \
    {                                                                                              \
        0, (FmtValue[]){},                                                                         \
    }

#define PRINT_ARGS_N(...)                                                                          \
    (FmtArgs)                                                                                      \
    {                                                                                              \
        GET_ARG_COUNT(__VA_ARGS__), (FmtValue[]){MAP(SELECT_VALUE, __VA_ARGS__)},                  \
    }

#define PRINT_ARGS(...) PRINT_ARGS_##__VA_OPT__(N)(__VA_ARGS__)

#define fmt$(WRITER, FORMAT, ...) fmt_impl((Writer *) WRITER, FORMAT, PRINT_ARGS(__VA_ARGS__))

void fmt_impl(Writer *writer, char const *fmt, FmtArgs args);