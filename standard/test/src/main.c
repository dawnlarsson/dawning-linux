#include "../../library.c"

#define test(test_name) bool test_##test_name()
#define case(test_name) {#test_name, test_##test_name}
#define fail(condition) if(!(condition)) return false
#define fail_equals(a, b) if((a) == (b)) return false
#define fail_not_equals(a, b) if((a) != (b)) return false

typedef bool(address_to dawn_test_function)();

typedef struct
{
        string_address name;
        dawn_test_function function;
} dawn_test;

p32 address_to p32_nulled = ((address_any)0);

p8 test_write_buffer[1000];
positive test_write_pos = 0;

fn test_writer(address_any data, positive length) {
        if(length == 0) length = string_length(data);
        memory_copy(test_write_buffer + test_write_pos, data, length);
        test_write_pos += length;
}

test(p8_sizeof) { fail_not_equals(sizeof(p8), 1); return true; }
test(p8_bytes_constant) { fail_not_equals(p8_bytes, 1); return true; }
test(p8_max) { fail_not_equals(p8_max, 255); return true; }
test(p8_min) { fail_not_equals(p8_min, 0); return true; }
test(p8_overflow) { fail_not_equals((p8)(p8_max + 1), 0); return true; }
test(p8_underflow) { fail_not_equals((p8)(p8_min - 1), p8_max); return true; }

test(b8_sizeof) { fail_not_equals(sizeof(b8), 1); return true; }
test(b8_bytes_constant) { fail_not_equals(b8_bytes, 1); return true; }
test(b8_max) { fail_not_equals(b8_max, 127); return true; }
test(b8_min) { fail_not_equals(b8_min, -128); return true; }
test(b8_overflow) { fail_not_equals((b8)(b8_max + 1), b8_min); return true; }
test(b8_underflow) { fail_not_equals((b8)(b8_min - 1), b8_max); return true; }

test(p16_sizeof) { fail_not_equals(sizeof(p16), 2); return true; }
test(p16_bytes_constant) { fail_not_equals(p16_bytes, 2); return true; }
test(p16_max) { fail_not_equals(p16_max, 65535); return true; }
test(p16_min) { fail_not_equals(p16_min, 0); return true; }
test(p16_overflow) { fail_not_equals((p16)(p16_max + 1), 0); return true; }
test(p16_underflow) { fail_not_equals((p16)(p16_min - 1), p16_max); return true; }

test(b16_sizeof) { fail_not_equals(sizeof(b16), 2); return true; }
test(b16_bytes_constant) { fail_not_equals(b16_bytes, 2); return true; }
test(b16_max) { fail_not_equals(b16_max, 32767); return true; }
test(b16_min) { fail_not_equals(b16_min, -32768); return true; }
test(b16_overflow) { fail_not_equals((b16)(b16_max + 1), b16_min); return true; }
test(b16_underflow) { fail_not_equals((b16)(b16_min - 1), b16_max); return true; }

test(p32_sizeof) { fail_not_equals(sizeof(p32), 4); return true; }
test(p32_bytes_constant) { fail_not_equals(p32_bytes, 4); return true; }
test(p32_max) { fail_not_equals(p32_max, 4294967295U); return true; }
test(p32_min) { fail_not_equals(p32_min, 0); return true; }
test(p32_overflow) { fail_not_equals((p32)(p32_max + 1), 0); return true; }
test(p32_underflow) { fail_not_equals((p32)(p32_min - 1), p32_max); return true; }

test(b32_sizeof) { fail_not_equals(sizeof(b32), 4); return true; }
test(b32_bytes_constant) { fail_not_equals(b32_bytes, 4); return true; }
test(b32_max) { fail_not_equals(b32_max, 2147483647); return true; }
test(b32_min) { fail_not_equals(b32_min, -2147483648); return true; }
test(b32_overflow) { fail_not_equals((b32)(b32_max + 1), b32_min); return true; }
test(b32_underflow) { fail_not_equals((b32)(b32_min - 1), b32_max); return true; }

test(p64_sizeof) { fail_not_equals(sizeof(p64), 8); return true; }
test(p64_bytes_constant) { fail_not_equals(p64_bytes, 8); return true; }
test(p64_max) { fail_not_equals(p64_max, 18446744073709551615U); return true; }
test(p64_min) { fail_not_equals(p64_min, 0); return true; }
test(p64_overflow) { fail_not_equals((p64)(p64_max + 1), 0); return true; }
test(p64_underflow) { fail_not_equals((p64)(p64_min - 1), p64_max); return true; }

test(b64_sizeof) { fail_not_equals(sizeof(b64), 8); return true; }
test(b64_bytes_constant) { fail_not_equals(b64_bytes, 8); return true; }
test(b64_max) { fail_not_equals(b64_max, 9223372036854775807); return true; }
test(b64_min) { fail_not_equals(b64_min, -9223372036854775808); return true; }
test(b64_overflow) { fail_not_equals((b64)(b64_max + 1), b64_min); return true; }
test(b64_underflow) { fail_not_equals((b64)(b64_min - 1), b64_max); return true; }

test(p128_sizeof) { fail_not_equals(sizeof(p128), 16); return true; }
test(p128_bytes_constant) { fail_not_equals(p128_bytes, 16); return true; }
test(p128_max) { fail_not_equals(p128_max, 340282366920938463463374607431768211455U); return true; }
test(p128_min) { fail_not_equals(p128_min, 0); return true; }
test(p128_overflow) { fail_not_equals((p128)(p128_max + 1), 0); return true; }
test(p128_underflow) { fail_not_equals((p128)(p128_min - 1), p128_max); return true; }

test(b128_sizeof) { fail_not_equals(sizeof(b128), 16); return true; }
test(b128_bytes_constant) { fail_not_equals(b128_bytes, 16); return true; }
test(b128_max) { fail_not_equals(b128_max, 170141183460469231731687303715884105727); return true; }
test(b128_min) { fail_not_equals(b128_min, -170141183460469231731687303715884105728); return true; }
test(b128_overflow) { fail_not_equals((b128)(b128_max + 1), b128_min); return true; }
test(b128_underflow) { fail_not_equals((b128)(b128_min - 1), b128_max); return true; }

test(f32_sizeof) { fail_not_equals(sizeof(f32), 4); return true; }
test(f32_bytes_constant) { fail_not_equals(f32_bytes, 4); return true; }
test(f32_max) { fail_not_equals(f32_max, 3.402823466e+38f); return true; }
test(f32_min) { fail_not_equals(f32_min, 1.175494351e-38f); return true; }

test(f64_sizeof) { fail_not_equals(sizeof(f64), 8); return true; }
test(f64_bytes_constant) { fail_not_equals(f64_bytes, 8); return true; }
test(f64_max) { fail_not_equals(f64_max, 1.7976931348623157e+308); return true; }
test(f64_min) { fail_not_equals(f64_min, 2.2250738585072014e-308); return true; }

test(f128_sizeof) { fail_not_equals(sizeof(f128), 16); return true; }
test(f128_bytes_constant) { fail_not_equals(f128_bytes, 16); return true; }
test(f128_max) { fail_not_equals(f128_max, 1.189731495357231765e+4932L); return true; }
test(f128_min) { fail_not_equals(f128_min, 3.362103143112093506e-4932L); return true; }

test(bit_operations) {
        p32 value = 0;

        for(int i=0; i<32; i++) {
            bit_set(i, &value);
            fail(bit_test(i, &value));
        }
        
        fail_not_equals(value, 0xFFFFFFFF);
        
        for(int i=0; i<32; i++) {
            bit_clear(i, &value);
            fail(!bit_test(i, &value));
        }
        
        fail_not_equals(value, 0);
        
        bit_flip(0, &value);
        fail_not_equals(value, 1);
        
        bit_flip(0, &value);
        fail_not_equals(value, 0);
        
        bit_set(31, &value);
        fail(bit_test(31, &value));

        return true;
}

test(addresses) {
        positive some_positive = 123456;
        positive address_to ptr = &some_positive;

        fail_not_equals(address_to ptr, some_positive);
        fail_not_equals(ptr, &some_positive);
        
        positive address_to null_ptr = (positive address_to)0;
        fail(is_null(null_ptr));
        
        positive arr[2] = {1,2};
        positive address_to arr_ptr = &arr[0];
        fail_not_equals(*(arr_ptr+1), 2);

        return true;
}

test(is_null) {
        fail(is_null(p32_nulled));
        fail(is_null(null));
        fail(is_null(0));
        fail(!is_null(&p32_nulled));
        
        positive value = 0;
        fail(!is_null(&value));
        
        int stack_var = 1;
        fail(!is_null(&stack_var));

        static int static_var = 2;
        fail(!is_null(&static_var));

        return true;
}

// Atomic operations test (basic)
test(atomic_operations) {
        positive value = 0;
        
        atomic_add(&value, 5);
        fail_not_equals(value, 5);
        
        atomic_sub(&value, 2);
        fail_not_equals(value, 3);
        
        atomic_inc(&value);
        fail_not_equals(value, 4);
        
        atomic_dec(&value);
        fail_not_equals(value, 3);
        
        positive old = atomic_exchange(&value, 10);
        fail_not_equals(old, 3);
        fail_not_equals(value, 10);
        
        bool success = atomic_compare_exchange(&value, 10, 20);
        fail(success);
        fail_not_equals(value, 20);
        
        success = atomic_compare_exchange(&value, 10, 30);
        fail(!success);
        fail_not_equals(value, 20);
        
        return true;
}

test(memory_fill) {
        p8 buffer[100];
        
        memory_fill(buffer, 0x42, 100);
        
        for(positive i = 0; i < 100; i++) {
                fail_not_equals(buffer[i], 0x42);
        }
        
        memory_fill(buffer, 0, 50);
        
        for(positive i = 0; i < 50; i++) {
                fail_not_equals(buffer[i], 0);
        }
        
        for(positive i = 50; i < 100; i++) {
                fail_not_equals(buffer[i], 0x42);
        }

        memory_fill(buffer, 0x99, 0);
        
        for(positive i = 0; i < 100; i++) {
                fail(buffer[i] == 0 || buffer[i] == 0x42);
        }
        
        memory_fill(buffer, 0xFF, 100);
        
        for(positive i = 0; i < 100; i++) {
                fail_not_equals(buffer[i], 0xFF);
        }
        
        return true;
}

test(memory_copy) {
        
        p8 buffer[] = "1234567890";
        p8 source[] = "Hello, World!";
        p8 destination[50] = {0};
        
        memory_copy(buffer + 2, buffer, 5);
        fail_not_equals(buffer[2], '1');
        fail_not_equals(buffer[6], '5');
        
        /*
        // non-overlapping regions
        memory_copy(destination, source, 16);
        fail_not_equals(string_compare(destination, source), 0);
        */

        return true;
}

test(string_length) {
        
        fail_not_equals(string_length(""), 0);
        fail_not_equals(string_length("a"), 1);
        fail_not_equals(string_length("Hello"), 5);
        fail_not_equals(string_length("Dawning\0Hidden"), 7);
        
        p8 buffer[100];
        memory_fill(buffer, 'A', 99);
        
        buffer[99] = end;
        fail_not_equals(string_length(buffer), 99);
        
        p8 only_null[1] = {end};
        fail_not_equals(string_length(only_null), 0);

        return true;
}

test(string_compare) {
        fail_not_equals(string_compare("", ""), 0);
        fail_not_equals(string_compare("abc", "abc"), 0);
        fail(string_compare("abc", "abd") < 0);
        fail(string_compare("abd", "abc") > 0);
        fail(string_compare("abc", "abcd") < 0);
        fail(string_compare("abcd", "abc") > 0);
        fail(string_compare("", "a") < 0);
        fail(string_compare("a", "") > 0);

        return true;
}

test(string_copy) {
        p8 dest[100];
        
        string_copy(dest, "Hello");
        fail_not_equals(string_compare(dest, "Hello"), 0);
        
        string_copy(dest, "");
        fail_not_equals(string_length(dest), 0);

        string_copy(dest, "A very long string that tests the copy function");
        fail_not_equals(string_length(dest), 47);
        
        string_copy(dest, dest);
        fail_not_equals(string_compare(dest, "A very long string that tests the copy function"), 0);
        
        return true;
}

test(string_copy_max) {

        p8 dest[100];

        memory_fill(dest, 'X', 100);
        string_copy_max(dest, "Hello, World!", 5);
        
        fail_not_equals(dest[5], 'X');
        fail_not_equals(dest[0], 'H');
        fail_not_equals(dest[4], 'o');

        /*
        string_copy_max(dest, "Hi", 10);
        fail_not_equals(dest[2], end);
        */

        string_copy_max(dest, "Hello", 0);
        fail_not_equals(dest[0], 'H');
        
        return true;
}

test(string_first_of) {
        string_address result;

        result = string_first_of("Hello, World!", 'o');
        fail(result != null);
        fail_not_equals(*result, 'o');
        
        result = string_first_of("Hello, World!", 'z');
        fail_not_equals(result, null);
        
        result = string_first_of("Hello, World!", end);
        fail(result != null);
        fail_not_equals(*result, end);
        
        result = string_first_of("abc", 'a');
        fail(result != null);
        fail_not_equals(*result, 'a');
        
        result = string_first_of("abc", 'c');
        fail(result != null);
        fail_not_equals(*result, 'c');
        
        return true;
}

test(string_last_of) {
        string_address result;

        result = string_last_of("Hello, World!", 'o');
        fail(result != null);
        fail_not_equals(*result, 'o');
        
        result = string_last_of("Hello, World!", 'H');
        fail(result != null);
        
        result = string_last_of("Hello, World!", 'z');
        fail_not_equals(result, null);
        
        result = string_last_of("abc", 'c');
        fail(result != null);
        fail_not_equals(*result, 'c');
        
        result = string_last_of("abc", 'a');
        fail(result != null);
        fail_not_equals(*result, 'a');
        
        return true;
}

test(string_cut) {
        p8 buffer[] = "Hello, World!";
        
        string_address result = string_cut(buffer, ' ');
        fail(result != null);
        fail_not_equals(string_compare(buffer, "Hello,"), 0);
        fail_not_equals(string_compare(result, "World!"), 0);
        
        p8 buffer2[] = "NoSpaces";
        result = string_cut(buffer2, ' ');
        fail_not_equals(result, null);
        
        p8 buffer3[] = "End ";
        result = string_cut(buffer3, ' ');
        fail_not_equals(result, null);

        /*
        p8 buffer4[] = " Xcut";
        result = string_cut(buffer4, ' ');
        fail(result != null);
        fail_not_equals(string_compare(buffer4, ""), 0);
        fail_not_equals(string_compare(result, "Xcut"), 0);
        */

        return true;
}

test(string_replace_all) {
        p8 buffer2[] = "aaaa";
        string_replace_all(buffer2, 'a', 'b');
        fail_not_equals(string_compare(buffer2, "bbbb"), 0);
        
        p8 buffer3[] = "cccc";
        string_replace_all(buffer3, 'c', 'c');
        fail_not_equals(string_compare(buffer3, "cccc"), 0);

        p8 buffer4[] = "dddd";
        string_replace_all(buffer4, 'z', 'y');
        fail_not_equals(string_compare(buffer4, "dddd"), 0);
        
        return true;
}

test(string_format_basic) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "Hello %s!", "World");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "Hello World!"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "%% test");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "% test"), 0);
        
        return true;
}

test(string_format_numbers) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "Positive: %p", 12345);
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "Positive: 12345"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "Bipolar: %b", -42);
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "Bipolar: -42"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "Zero: %p", 0);
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "Zero: 0"), 0);
        
        return true;
}

test(string_format_mixed) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "%s has %p items worth %b each", "Dawn", 5, -10);

        test_write_buffer[test_write_pos] = end;

        fail_not_equals(string_compare(test_write_buffer, "Dawn has 5 items worth -10 each"), 0);
        
        return true;
}

// Path operations
test(path_basename) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        path_basename(test_writer, "/usr/bin/test");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "test"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "/usr/bin/");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "bin"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "/");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "/"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "test.txt");
        test_write_buffer[test_write_pos] = end;
        fail_not_equals(string_compare(test_write_buffer, "test.txt"), 0);
        
        return true;
}

test(str_macro) {
        string_address data;
        positive length;
        
        data = str("Hello");
        fail_not_equals(data[0], 'H');
        fail_not_equals(data[1], 'e');
        
        return true;
}

test(string_end) {
        fail_not_equals(end, '\0');
        fail_not_equals(end, 0);
        
        p8 buffer[] = "Test";
        fail_not_equals(buffer[4], end);
        
        return true;
}

test(writer_pattern) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        test_writer("Hello", 5);
        fail_not_equals(test_write_pos, 5);
        fail_not_equals(string_compare(test_write_buffer, "Hello"), 0);
        
        test_writer(", ", 2);
        test_writer("World!", 0);
        fail_not_equals(string_compare(test_write_buffer, "Hello, World!"), 0);
        
        return true;
}


dawn_test dawn_tests[] = {

        case(p8_sizeof),
        case(p8_bytes_constant),
        case(p8_max),
        case(p8_min),
        case(p8_overflow),
        case(p8_underflow),

        case(b8_sizeof),
        case(b8_bytes_constant),
        case(b8_max),
        case(b8_min),
        case(b8_overflow),
        case(b8_underflow),

        case(p16_sizeof),
        case(p16_bytes_constant),
        case(p16_max),
        case(p16_min),
        case(p16_overflow),
        case(p16_underflow),

        case(b16_sizeof),
        case(b16_bytes_constant),
        case(b16_max),
        case(b16_min),
        case(b16_overflow),
        case(b16_underflow),

        case(p32_sizeof),
        case(p32_bytes_constant),
        case(p32_max),
        case(p32_min),
        case(p32_overflow),
        case(p32_underflow),

        case(b32_sizeof),
        case(b32_bytes_constant),
        case(b32_max),
        case(b32_min),
        case(b32_overflow),
        case(b32_underflow),
        
        case(p64_sizeof),
        case(p64_bytes_constant),
        case(p64_max),
        case(p64_min),
        case(p64_overflow),
        case(p64_underflow),

        case(b64_sizeof),
        case(b64_bytes_constant),
        case(b64_max),
        case(b64_min),
        case(b64_overflow),
        case(b64_underflow),

        case(p128_sizeof),
        case(p128_bytes_constant),
        case(p128_max),
        case(p128_min),
        case(p128_overflow),
        case(p128_underflow),
        
        case(b128_sizeof),
        case(b128_bytes_constant),
        case(b128_max),
        case(b128_min),
        case(b128_overflow),
        case(b128_underflow),

        case(f32_sizeof),
        case(f32_bytes_constant),
        case(f32_max),
        case(f32_min),

        case(f64_sizeof),
        case(f64_bytes_constant),
        case(f64_max),
        case(f64_min),

        case(f128_sizeof),
        case(f128_bytes_constant),
        case(f128_max),
        case(f128_min),


        case(bit_operations),
        case(addresses),
        case(is_null),
        case(atomic_operations),
        
        case(memory_fill),
        case(memory_copy),
        
        case(string_length),
        case(string_compare),
        case(string_copy),
        case(string_copy_max),
        case(string_first_of),
        case(string_last_of),
        case(string_cut),
        case(string_replace_all),
        case(string_format_basic),
        case(string_format_numbers),
        case(string_format_mixed),
        
        case(path_basename),
        
        case(str_macro),
        
        case(string_end),

        case(writer_pattern),
        
        {null, null},
};

b32 main()
{
        dawn_test address_to test = dawn_tests;
        positive passed = 0;
        positive failed = 0;

        log_direct(str("Dawning C Library Tests\n\n"));

        while (test->name)
        {
                log_direct(test->name, string_length(test->name));

                bool result = test->function();

                if (!result) {
                        log_direct(str("  XXXXXXXXXXXXXXXXX  FAILED\n"));
                        failed++;
                }
                else {
                        log_direct(str(" PASSED\n"));
                        passed++;
                }
                test++;
        }

        string_format(log, "\n%p passed, %p failed\n", passed, failed);

        log_flush();

        return failed > 0 ? 1 : 0;
}