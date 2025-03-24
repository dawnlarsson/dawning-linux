/*
        Dawning Experimental C standard library
        intended for tiny C programs that run in the distro
        without any runtime requirements (no linking!)

        Dawn Larsson - Apache-2.0 license
        github.com/dawnlarsson/dawning-linux/library/standard.c

        www.dawning.dev

        use the accompanying build shell script to compile
        $ sh build <source_file.c> <output_file_name>
*/

#ifndef DAWN_MODERN_C
#define DAWN_MODERN_C

#if defined(__linux__)
#define LINUX
#elif defined(__APPLE__)
#define MACOS
#elif defined(_WIN32)
#define WINDOWS
#elif defined(__IOS__)
#define IOS
#elif defined(__ANDROID__)
#define ANDROID
#endif

#if defined(__x86_64__) || defined(_M_X64)
#define X64
#define BITS 64
#elif defined(__i386) || defined(_M_IX86)
#define X86
#define BITS 32
#elif defined(__aarch64__) || defined(_M_ARM64)
#define ARM64
#define BITS 64
#elif defined(__arm__) || defined(_M_ARM)
#define ARM32
#define BITS 32
#elif defined(__riscv)
#if __riscv_xlen == 64
#define RISCV64
#define BITS 64
#elif __riscv_xlen == 32
#define RISCV32
#define BITS 32
#endif
#elif defined(__PPC64__)
#define PPC64
#define BITS 64
#elif defined(__s390x__)
#define S390X
#define BITS 64
#endif

#if defined(__SSE__) || defined(__ARM_NEON)
#define SIMD
#endif

#if defined(X86) || defined(ARM32) || defined(RISCV32) || defined(RISCV64) || defined(ARM64)
#warning "Unsupported architecture TODO!"
#endif

#if defined(X64)
#define stdin 0
#define stdout 1
#define stderr 2
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
/* C23 does not require the second parameter for va_start. */
#define variable_arguments_start(ap, ...) __builtin_va_start(ap, 0)
#else
/* Versions before C23 do require the second parameter. */
#define variable_arguments_start(ap, param) __builtin_va_start(ap, param)
#endif
#define variable_arguments_end(ap) __builtin_va_end(ap)
#define variable_argument(ap, type) __builtin_va_arg(ap, type)
#define variable_argument_copy(dest, src) __builtin_va_copy(dest, src)

typedef __builtin_va_list variable_arguments;

#define FLAT __attribute__((flatten))
#define NO_INLINE __attribute__((noinline))
#define PURE __attribute__((pure))
#define NAKED __attribute__((naked))
#define INLINE __attribute__((always_inline))
#define NO_FRAME __attribute__((noframe))
#define KEEP __attribute__((used))
#define DEAD_END __attribute__((noreturn))
#define WEAK __attribute__((weak))

#define pub extern __attribute__((visibility("default")))

#define ADDRESS_TO *
#define ADDRESS_OF &
#define ADDRESS void *
#define NULL_ADDRESS ((void *)0)
#define IS_NULL_ADDRESS(ptr) ((ptr) == NULL_ADDRESS)
#define NULL 0

#define ANSI "\033["

#define TERM_CLEAR_SCREEN ANSI "2J" ANSI "H"
#define TERM_HIDE_CURSOR ANSI "?25l"
#define TERM_SHOW_CURSOR ANSI "?25h"

#define TERM_RESET ANSI "0m"
#define TERM_BOLD ANSI "1m"
#define TERM_DIM ANSI "2m"
#define TERM_UNDERLINED ANSI "4m"
#define TERM_BLINK ANSI "5m"
#define TERM_REVERSE ANSI "7m"
#define TERM_HIDDEN ANSI "8m"
#define TERM_INVERT ANSI "7m"

#define TERM_BLACK_DARK ANSI "30m"
#define TERM_RED_DARK ANSI "31m"
#define TERM_GREEN_DARK ANSI "32m"
#define TERM_YELLOW_DARK ANSI "33m"
#define TERM_BLUE_DARK ANSI "34m"
#define TERM_MAGENTA_DARK ANSI "35m"
#define TERM_CYAN_DARK ANSI "36m"
#define TERM_WHITE_DARK ANSI "37m"

#define TERM_BLACK ANSI "90m"
#define TERM_RED ANSI "91m"
#define TERM_GREEN ANSI "92m"
#define TERM_YELLOW ANSI "93m"
#define TERM_BLUE ANSI "94m"
#define TERM_MAGENTA ANSI "95m"
#define TERM_CYAN ANSI "96m"
#define TERM_WHITE ANSI "97m"

// ### Values that never can be negative
#define positive_range unsigned

// ### Values that can be negative
#define bipolar_range signed

/// A non value returning function
typedef void fn;

// ### Positive range 8 bit integer
// range:       0 to +255
// memory:      [ 00000000 ]
// hex:         [ 0x00 ]
// linguistic:  (zero) to (plus) two hundred fifty-five
// traditional: char
// alt:         array of 8 bits
typedef char p8;
#define p8_max 255
#define p8_min 0
#define p8_char_max 3
#define p8_bytes 1
#define p8_bits 8

// ### Bipolar range 8 bit integer
// range:       -128 to +127
// memory:      [ 00000000 ]
// hex:         [ 0x00 ]
// linguistic:  (minus) one hundred twenty-eight to (plus) one hundred twenty-seven
// traditional: signed char
// alt:         array of 8 bits
typedef bipolar_range char b8;
#define b8_max 127
#define b8_min -128
#define b8_char_max 4
#define b8_bytes 1
#define b8_bits 8

// ### Positive range 16 bit integer
// range:       0 to +65535
// memory:      [ 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 ]
// linguistic:  (zero) to (plus) sixty-five thousand...
// traditional:  short
// alt:         array of 16 bits
typedef short int p16;
#define p16_max 65535
#define p16_min 0
#define p16_char_max 6
#define p16_bytes 2
#define p16_bits 16

// ### Bipolar range 16 bit integer
// range:       -32768 to +32767
// memory:      [ 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 ]
// linguistic:  (minus) thirty-two thousand... to (plus) thirty-two thousand...
// traditional: signed short
// alt:         array of 16 bits
typedef bipolar_range short int b16;
#define b16_max 32767
#define b16_min -32768
#define b16_char_max 6
#define b16_bytes 2
#define b16_bits 16

// ### Positive range 32 bit integer
// range:       0 to +4294967295
// memory:      [ 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (zero) to (plus) four billion...
// traditional: int
// alt:         array of 32 bits
typedef int p32;
#define p32_max 4294967295
#define p32_min 0
#define p32_char_max 10
#define p32_bytes 4
#define p32_bits 32

// ### Bipolar range 32 bit integer
// range:       -2147483648 to +2147483647
// memory:      [ 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (minus) two billion... to (plus) two billion...
// traditional: signed int
// alt:         array of 32 bits
typedef bipolar_range int b32;
#define b32_max 2147483647
#define b32_min -2147483648
#define b32_char_max 11
#define b32_bytes 4
#define b32_bits 32

// ### Positive range 64 bit integer
// range:       0 to +18446744073709551615
// memory:      [ 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (zero) to (plus) eighteen quintillion...
// traditional: long int
// alt:         array of 64 bits
typedef long int p64;
#define p64_max 18446744073709551615
#define p64_min 0
#define p64_char_max 20
#define p64_bytes 8
#define p64_bits 64

// ### Bipolar range 64 bit integer
// range:       -9223372036854775808 to +9223372036854775807
// memory:      [ 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         [ 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (minus) nine quintillion... to (plus) nine quintillion...
// traditional: signed long int
// alt:         array of 64 bits
typedef bipolar_range long int b64;
#define b64_max 9223372036854775807
#define b64_min -9223372036854775808
#define b64_char_max 21
#define b64_bytes 8
#define b64_bits 64

// ### Positive range 128 bit integer
// range:       0 to +340282366920938463463374607431768211455
// memory:      2x [ 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         2x [ 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (zero) to (plus) three hundred forty undecillion...
// traditional: long long int
// alt:         array of 128 bits
typedef long long int p128;
#define p128_max 340282366920938463463374607431768211455
#define p128_min 0
#define p128_char_max 39
#define p128_bytes 16
#define p128_bits 128

// ### Bipolar range 128 bit integer
// range:       -170141183460469231731687303715884105727 to +170141183460469231731687303715884105727
// memory:      2x [ 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 | 00000000 ]
// hex:         2x [ 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 ]
// linguistic:  (minus) one hundred seventy undecillion... to (plus) one hundred seventy undecillion...
// traditional: signed long long int
// alt:         array of 128 bits
typedef bipolar_range long long int b128;
#define b128_max 170141183460469231731687303715884105727
#define b128_min -170141183460469231731687303715884105728
#define b128_char_max 40
#define b128_bytes 16
#define b128_bits 128

#if BITS != 64
__extension__ typedef bipolar_range long long int i64;
__extension__ typedef positive_range long long int u64;
#endif

typedef float f32;
#define f32_max 3.40282346638528859812e+38F
#define f32_min 1.17549435082228750797e-38F
#define f32_epsilon 1.1920928955078125e-07F
#define f32_char_max 10
#define f32_bytes 4
#define f32_bits 32

typedef double f64;
#define f64_max 1.79769313486231570815e+308
#define f64_min 2.22507385850720138309e-308
#define f64_epsilon 2.22044604925031308085e-16
#define f64_char_max 20
#define f64_bytes 8
#define f64_bits 64

typedef long double f128;
#define f128_max 1.18973149535723176508575932662800702e+4932
#define f128_min 3.36210314311209350626267781732175260e-4932
#define f128_epsilon 1.92592994438723585305597794258492732e-34
#define f128_char_max 40
#define f128_bytes 16
#define f128_bits 128

#if BITS == 64
typedef f64 decimal;
#define decimal_max f64_max
#define decimal_min f64_min
#define decimal_char_max f64_char_max
#define decimal_bytes f64_bytes
#define decimal_bits f64_bits
#else
typedef f32 decimal;
#define decimal_max f32_max
#define decimal_min f32_min
#define decimal_char_max f32_char_max
#define decimal_bytes f32_bytes
#define decimal_bits f32_bits
#endif

#if BITS == 64

// ### Positive range [native] bit integer
// recommended type for most cases (especially for memory addresses, or loops)
// where native is the default integer size of the system architecture
// that's compiled for, for example,
//
// 64 bit systems: positive == p64
// range:       0 to +18446744073709551615
//
// 32 bit systems: positive == p32
// range:       0 to +4294967295
//
typedef p64 positive;
#define positive_max p64_max
#define positive_min p64_min
#define positive_char_max p64_char_max
#define positive_bytes p64_bytes
#define positive_bits p64_bits

// ### Bipolar range [native] bit integer
// recommended type for most cases (especially for memory addresses, or loops)
// where native is the default integer size of the system architecture
// that's compiled for, for example,
//
// 64 bit systems: bipolar == b64
// range:       -9223372036854775808 to +9223372036854775807
//
// 32 bit systems: bipolar == b32
// range:       -2147483648 to +2147483647
typedef b64 bipolar;
#define bipolar_max b64_max
#define bipolar_min b64_min
#define bipolar_char_max b64_char_max
#define bipolar_bytes b64_bytes
#define bipolar_bits b64_bits

// ### Native Decimal range floating point
// range:       1.7E-308 to 1.7E+308
typedef f64 decimal;
#define decimal_max f64_max
#define decimal_min f64_min
#define decimal_char_max f64_char_max
#define decimal_bytes f64_bytes
#define decimal_bits f64_bits

#else

// ### Positive range [native] bit integer
// recommended type for most cases (especially for memory addresses, or loops)
// where native is the default integer size of the system architecture
// that's compiled for, for example,
//
// 64 bit systems: positive == p64
// range:       0 to +18446744073709551615
//
// 32 bit systems: positive == p32
// range:       0 to +4294967295
//
typedef p32 positive;
#define positive_max p32_max
#define positive_min p32_min
#define positive_char_max p32_char_max
#define positive_bytes p32_bytes
#define positive_bits p32_bits

// ### Bipolar range [native] bit integer
// recommended type for most cases (especially for memory addresses, or loops)
// where native is the default integer size of the system architecture
// that's compiled for, for example,
//
// 64 bit systems: bipolar == b64
// range:       -9223372036854775808 to +9223372036854775807
//
// 32 bit systems: bipolar == b32
// range:       -2147483648 to +2147483647
typedef b32 bipolar;
#define bipolar_max b32_max
#define bipolar_min b32_min
#define bipolar_char_max b32_char_max
#define bipolar_bytes b32_bytes
#define bipolar_bits b32_bits

// ### Native Decimal range floating point

typedef f32 decimal;
#define decimal_max f32_max
#define decimal_min f32_min
#define decimal_char_max f32_char_max
#define decimal_bytes f32_bytes
#define decimal_bits f32_bits
#endif

typedef typeof(sizeof(0)) sized;

#define false 0
#define true 1
#define bool p8

// ### String address
// a pointer to a string in memory, usually the first p8 character of the string
typedef p8 ADDRESS_TO string_address;
typedef p8 string[];

#define string_index(source, index) (ADDRESS_TO((source) + (index)))
#define string_get(source) (ADDRESS_TO(source))
#define string_set(source, value) (ADDRESS_TO(source) = (value))
#define string_is(source, value) (ADDRESS_TO(source) == (value))
#define string_equals(source, input) (strcmp(source, input) == 0)

#define min(value, input) ((value)greater_than(input) ? (value) : (input))
#define max(value, input) ((value)less_than(input) ? (value) : (input))
#define square(value) ((value) * (value))
#define cube(value) ((value) * (value) * (value))
#define mod(value, input) ((value) % (input))
#define floor(a) ((decimal)((bipolar)(a)))

#define clamp(value, min, max) ((value)less_than(min) ? (min) : (value)greater_than(max) ? (max) \
                                                                                         : (value))

//
// these are 1:1 with nasm syntax, so you can easily convert nasm code to this format
//
// Define data in memory as b8 (bipolar 8-bit / byte)
// in nasm: db
#define b8_asm(...) asm volatile(".byte " #__VA_ARGS__ "\n")

// Define data in memory as b16 (bipolar 16-bit / word)
// in nasm: dw
#define b16_asm(...) asm volatile(".word " #__VA_ARGS__ "\n")

// Define data in memory as b32 (bipolar 32-bit / double word)
// in nasm: dd
#define b32_asm(...) asm volatile(".long " #__VA_ARGS__ "\n")

// Define data in memory as b64 (bipolar 64-bit / quad word)
// in nasm: dq
#define b64_asm(...) asm volatile(".quad " #__VA_ARGS__ "\n")

// behold, the only sane and consistent named assembly instructions cross architectures
#define asm_add "add"
#define asm_sub "sub"

// Register mapping
#ifdef X64

#define asm_copy_ "mov"
#define asm_copy_64 "movq"
#define asm_copy_32 "movl"

#define asm_store "mov"
#define asm_jump "jmp"
#define asm_branch "je"

#define reg_0 "%rax"
#define reg_1 "%rdi"
#define reg_2 "%rsi"
#define reg_3 "%rdx"
#define reg_4 "%rcx"
#define reg_5 "%r8"
#define reg_6 "%r9"
#define tem_0 "%r10"
#define tem_1 "%r11"
#define stack_pointer "%rsp"
#define frame_pointer "%rbp"

#if defined(X64)
#define asm_copy asm_copy_64
#else
#define asm_copy asm_copy_32
#endif

#elif defined(ARM64)
#define asm_copy "ldr"
#define asm_store "str"
#define asm_jump "bl"
#define asm_branch "beq"
#define system_invoke "svc 0"

#define reg_0 "x0"
#define reg_1 "x1"
#define reg_2 "x2"
#define reg_3 "x3"
#define reg_4 "x4"
#define reg_5 "x5"
#define reg_6 "x6"
#define tem_0 "x9"
#define tem_1 "x10"
#define stack_pointer "sp"
#define frame_pointer "x29"
#elif defined(RISCV64)
#define asm_copy "ld"
#define asm_store "sd"
#define asm_jump "jalr"
#define asm_branch "beq"
#define system_invoke "ecall"

#define reg_0 "a0"
#define reg_1 "a1"
#define reg_2 "a2"
#define reg_3 "a3"
#define reg_4 "a4"
#define reg_5 "a5"
#define reg_6 "a6"
#define tem_0 "t0"
#define tem_1 "t1"
#define stack_pointer "sp"
#define frame_pointer "s0"
#endif

#define ir(asm_args...) \
        asm volatile(asm_args)

#define copy(where, from) ir(asm_copy " " where "," from ";")
#define jump(where) ir(asm_jump " " where ";")
#define branch(where) ir(asm_branch " " where ";")
#define add(what, with) ir(asm_add " " what "," with ";")
#define sub(what, with) ir(asm_sub " " what "," with ";")
#define system_return ir("ret")
#define system_invoke ir("syscall")

#define call(what) ir("call " what ";")

// Arguments passed to fn_asm functions are loaded into registers by C
// each argument is sequentially loaded into registers, starting from reg_0
// and ending at reg_6, if there are more arguments than registers, the
// remaining arguments are loaded into the stack, and the stack pointer
// is moved to the last argument, and the frame pointer is moved to the
#define fn_asm(name, return_type, arguments...) \
        static inline NAKED return_type name(arguments)

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call, bipolar, positive syscall)
{
        // syscall number
        copy(reg_0, reg_0);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_1, bipolar, positive syscall, positive argument_1)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_2, bipolar, positive syscall, positive argument_1, positive argument_2)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        // syscall argument
        copy(reg_3, reg_2);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_3, bipolar, positive syscall, positive argument_1, positive _startargument_2, positive argument_3)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        // syscall argument
        copy(reg_3, reg_2);

        // syscall argument
        copy(reg_4, reg_3);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_4, bipolar, positive syscall, positive argument_1, positive argument_2, positive argument_3, positive argument_4)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        // syscall argument
        copy(reg_3, reg_2);

        // syscall argument
        copy(reg_4, reg_3);

        // syscall argument
        copy(reg_5, reg_4);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_5, bipolar, positive syscall, positive argument_1, positive argument_2, positive argument_3, positive argument_4, positive argument_5)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        // syscall argument
        copy(reg_3, reg_2);

        // syscall argument
        copy(reg_4, reg_3);

        // syscall argument
        copy(reg_5, reg_4);

        // syscall argument
        copy(reg_6, reg_5);

        system_invoke;
        system_return;
}

// ### System call
// invokes operating system functions externally to the program
// returns: status code of the system call
// syscall: the system call number
fn_asm(system_call_6, bipolar, positive syscall, positive argument_1, positive argument_2, positive argument_3, positive argument_4, positive argument_5, positive argument_6)
{
        // syscall number
        copy(reg_1, reg_0);

        // syscall argument
        copy(reg_2, reg_1);

        // syscall argument
        copy(reg_3, reg_2);

        // syscall argument
        copy(reg_4, reg_3);

        // syscall argument
        copy(reg_5, reg_4);

        // syscall argument
        copy(reg_6, reg_5);

        // syscall argument
        copy(tem_0, reg_6);

        system_invoke;
        system_return;
}

// Writer functions are intended as flexible outout functions passed to functions as arguments
// and should be easy for compiler to optimize into a zero cost abstraction
// if length is zero, the function should write until a null terminator is reached (string_length)
// writers redused file size, faster, and more flexible
typedef fn(ADDRESS_TO writer)(ADDRESS data, positive length);

typedef fn(ADDRESS_TO writer_string)(string_address string);
typedef fn(ADDRESS_TO writer_string_len)(string_address string, positive length);

// Helper function for writing static strings to a writer with data + length
// example with:
//      write(str("Hello, world!\n"));
// example without:
//      write("Hello, world!\n", 14); // error prone!
#define str(string) (string), (sizeof(string))

// User required implementations
b32 main();

// Platform required implementations
fn exit(b32 code);
fn sleep(p32 seconds, p32 nanoseconds);
fn _start();

#if defined(X64)
// ### Get CPU time (Time Stamp Counter)
// returns: the current CPU time
p64 get_cpu_time()
{
        p32 hi, lo;
        ir("rdtsc" : "=a"(lo), "=d"(hi));
        return ((p64)hi << 32) | lo;
}
#elif defined(ARM64)
// ### Get CPU time (Time Stamp Counter)
// returns: the current CPU time
p64 get_cpu_time()
{
        p64 result;
        ir("mrs %0, cntvct_el0" : "=r"(result));
        return result;
}
#elif defined(RISCV64)
// ### Get CPU time (Time Stamp Counter)
// returns: the current CPU time
p64 get_cpu_time()
{
        p64 result;
        ir("rdtime %0" : "=r"(result));
        return result;
}
#endif

// ### Fill a memory block with the same value
// fills a memory block with the same value
// returns: destination address
// destination: the memory block to fill
// traditional: memset
ADDRESS memory_fill(ADDRESS destination, b8 value, positive size)
{
        b8 ADDRESS_TO dest = (b8 ADDRESS_TO)destination;

        while (size--)
                ADDRESS_TO dest++ = (b8)value;

        return destination;
}

// ### Fill source memory block with destination memory block
// copies a memory block from source to destination
// returns: destination address
// destination: the memory block to copy to
// source: the memory block to copy from
// traditional: memcpy
ADDRESS memory_copy(ADDRESS destination, ADDRESS source, positive size)
{
        b8 ADDRESS_TO dest = (b8 ADDRESS_TO)destination;
        b8 ADDRESS_TO src = (b8 ADDRESS_TO)source;

        while (size--)
                ADDRESS_TO dest++ = ADDRESS_TO src++;

        return destination;
}

// ### Length of string segment in linear memory
// returns the length of a string terminated by a null character
// NOT a entire array length
// a string array can hold more than one string, null terminators
// are used to separate strings, so where you run strlen is important
// traditional: strlen
positive string_length(string_address source)
{
        string_address step = source;

        while (string_get(step))
                step++;

        return step - source;
}

// ### Compare two string segments
// returns: 0 - if strings are equal
// returns: positive number - if first string is greater
// returns: negative number - if second string is greater
// traditional: strcmp
b32 string_compare(string_address source, string_address input)
{
        while (string_get(source) && string_get(input))
        {
                if (string_get(source) != string_get(input))
                        break;

                source++;
                input++;
        }

        return (b8)string_get(source) - (b8)string_get(input);
}

// ### Copy string segment
// copies a string segment from source to destination
// returns: destination address
// destination: the memory block to copy to
// source: the memory block to copy from
// traditional: strcpy
string_address string_copy(string_address destination, string_address source)
{
        string_address start = destination;

        while (string_get(source))
                string_set(destination++, string_get(source++));

        string_set(destination, '\0');

        return start;
}

// ### Find first character in string segment
// returns: address of the first occurrence of the character
// returns: NULL if the character is not found
// source: the memory block to search
// character: the character to search for
// traditional: strchr
string_address string_first_of(string_address source, p8 character)
{
        while (string_get(source))
        {
                if (string_get(source) == character)
                        return source;

                source++;
        }

        return (string_get(source) == character) ? source : NULL;
}

// ### Find last character in string segment
// returns: address of the last occurrence of the character
// returns: NULL if the character is not found
// source: the memory block to search
// character: the character to search for
// traditional: strrchr
string_address string_last_of(string_address source, p8 character)
{
        string_address last = NULL;

        while (string_get(source))
        {
                if (string_get(source) == character)
                        last = source;

                source++;
        }

        return last;
}

// ### Takes a positive number and writes out the string representation
fn positive_to_string(writer write, positive number)
{
        if (number == 0)
                return write("0", 1);

        p8 digits[32];
        positive count = 0;

        while (number > 0 && count < 32)
        {
                digits[count++] = '0' + (number % 10);
                number /= 10;
        }

        while (count > 0)
                write(&digits[--count], 1);
}

// ### Takes a bipolar number and writes out the string representation
fn bipolar_to_string(writer write, bipolar number)
{
        if (number > 0)
                return positive_to_string(write, (positive)number);

        write("-", 1);
        positive_to_string(write, (positive)(-number));
}

// ### Takes a path and writes out the last directory name
fn path_basename(writer write, string_address input)
{
        positive length = string_length(input);

        while (length > 1 && input[length - 1] == '/')
                length--;

        if (length == 1 && input[0] == '/')
                return write("/", 1);

        positive step = length;

        while (step > 0 && input[step - 1] != '/')
                step--;

        write(input + step, length - step);
}

// for compatibility, makes the linker happy
ADDRESS memset(ADDRESS destination, b8 value, positive size)
{
        return memory_fill(destination, value, size);
}

#ifdef DAWN_MODERN_C_COMPATIBILITY

typedef p8 u8;
typedef b8 i8;
typedef p16 u16;
typedef b16 i16;
typedef p32 u32;
typedef b32 i32;
typedef p64 u64;
typedef b64 i64;
typedef p128 u128;
typedef b128 i128;
typedef p64 usize;
typedef b64 isize;

typedef sized size_t;
typedef b128 intmax_t;
typedef p128 uintmax_t;
typedef b64 ptrdiff_t;
typedef unsigned long int uintptr_t;
typedef long int intptr_t;

// use memory_copy instead, this is for compatibility
positive memcpy(ADDRESS destination, ADDRESS source, positive size)
{
        return memory_copy(destination, source, size);
}

// use string_length instead, this is for compatibility
positive strlen(string_address source)
{
        return string_length(source);
}

// use string_compare instead, this is for compatibility
b32 strcmp(string_address source, string_address input)
{
        return string_compare(source, input);
}

// use string_copy instead, this is for compatibility
string_address strcpy(string_address destination, string_address source)
{
        return string_copy(destination, source);
}

// use string_first_of instead, this is for compatibility
string_address strchr(string_address source, p8 character)
{
        return string_first_of(source, character);
}

// use string_last_of instead, this is for compatibility
string_address strrchr(string_address source, p8 character)
{
        return string_last_of(source, character);
}

#endif // DAWN_MODERN_C_COMPATIBILITY

#ifndef DAWN_MODERN_C_NO_MATH

#define PI 3.14159265359f
#define PI_2x (PI * 2.0f)
#define PI_05x (PI * 0.5f)

#define CONVERSION_CONSTANTS                         \
        constexpr decimal RadToDeg = 180.0f / PI;    \
        constexpr decimal RadToTurn = 0.5f / PI;     \
        constexpr decimal DegToRad = PI / 180.0f;    \
        constexpr decimal DegToTurn = 0.5f / 180.0f; \
        constexpr decimal TurnToRad = PI / 0.5f;     \
        constexpr decimal TurnToDeg = 180.0f / 0.5f

#define AngleRad(value) (value)
#define AngleDeg(value) ((value) * DegToRad)
#define AngleTurn(value) ((value) * TurnToRad)

typedef union vector2
{
        struct
        {
                decimal x, y;
        };

        struct
        {
                decimal width, height;
        };

        decimal axis[2];

} vector2;

typedef union vector3
{
        struct
        {
                decimal x, y, z;
        };

        struct
        {
                decimal width, height, depth;
        };

        decimal axis[3];

} vector3;

typedef union vector4
{
        struct
        {
                decimal x, y, z, w;
        };

        struct
        {
                decimal width, height, depth, time;
        };

        decimal axis[4];

} vector4;

typedef vector4 quaternion;

typedef union matrix2
{
        decimal axis[2][2];
        vector2 colum[2];
} matrix2;

typedef union matrix3
{
        decimal axis[3][3];
        vector3 colum[3];
} matrix3;

typedef union matrix4
{
        decimal axis[4][4];
        vector4 colum[4];
} matrix4;

#endif // DAWN_MODERN_C_NO_MATH

#endif // DAWN_MODERN_C