/*
        Dawning
        DDL (Dumb Direct Language) + SOL

        A step between C and machine code,
        using SOL syntax and Dawning C Standard type system.

        Dawning SOL - sol (Sun) Dawn's simple language syntax
        Sol is a work in progress syntax system

        it's also experimental work on compiler stuff

        Dawn Larsson - Apache-2.0 license
*/

#include "library.c"

// if to build this as a standalone executable
#ifndef COMPILER_LIB_MODE
#include "linux.c"

b32 main()
{
}

#endif