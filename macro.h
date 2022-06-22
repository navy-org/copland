#pragma once 

#define loop for(;;)
#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,
#define PACKED [[gnu::packed]]
#define MAYBE_UNUSED [[maybe_unused]]
#define align_down$(__addr, __align) ((__addr) & ~((__align)-1))
#define align_up$(__addr, __align) (((__addr) + (__align)-1) & ~((__align)-1))

#define kib$(x) ((uint64_t) (x) * 1024)

#define mib$(x) (kib$(x) * 1024)

#define gib$(x) (mib$(x) * 1024)
