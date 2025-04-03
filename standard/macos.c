#ifndef DAWN_MODERN_C_PLATFORM_MACOS
#define DAWN_MODERN_C_PLATFORM_MACOS

#include "library.c"

fn exit()
{
        system_call_1(syscall(exit), 0);
}

fn start()
{
        b32 result = main();

        exit(result);
}

#endif