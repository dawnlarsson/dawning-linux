#include "../../library.c"

#define test(test_name) bool test_##test_name()
#define case(test_name) {#test_name, test_##test_name}
#define fail(condition) if(!(condition)) return false
#define fail_equals(a, b) if((a) != (b)) return false
#define fail_not_equals(a, b) if((a) == (b)) return false

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

test(addresses) {
        positive some_positive = 123456;
        positive address_to ptr = &some_positive;
        
        fail_equals(address_to ptr, some_positive);
        fail_equals(ptr, &some_positive);
        
        return true;
}

test(is_null) {
        fail(is_null(p32_nulled));
        fail(is_null(null));
        fail(is_null(0));
        fail(!is_null(&p32_nulled));
        
        positive value = 0;
        fail(!is_null(&value));
        
        return true;
}

test(type_sizes) {
        fail_equals(sizeof(p8), 1);
        fail_equals(sizeof(b8), 1);
        fail_equals(sizeof(p16), 2);
        fail_equals(sizeof(b16), 2);
        fail_equals(sizeof(p32), 4);
        fail_equals(sizeof(b32), 4);
        fail_equals(sizeof(p64), 8);
        fail_equals(sizeof(b64), 8);
        fail_equals(sizeof(f32), 4);
        fail_equals(sizeof(f64), 8);
        
        return true;
}

test(type_ranges) {
        fail_equals(p8_max, 255);
        fail_equals(p8_min, 0);
        fail_equals(b8_max, 127);
        fail_equals(b8_min, -128);
        fail_equals(p16_max, 65535);
        fail_equals(p32_max, 4294967295U);
        fail_equals(b32_max, 2147483647);
        fail_equals(b32_min, -2147483648);
        
        return true;
}

test(bit_operations) {
        p32 value = 0;
        
        bit_set(0, &value);
        fail_equals(value, 1);
        
        bit_set(3, &value);
        fail_equals(value, 9);
        
        fail(bit_test(0, &value));
        fail(bit_test(3, &value));
        fail(!bit_test(1, &value));
        
        bit_clear(0, &value);
        fail_equals(value, 8);
        
        bit_flip(3, &value);
        fail_equals(value, 0);
        
        bit_flip(7, &value);
        fail_equals(value, 128);
        
        return true;
}

// Atomic operations test (basic)
test(atomic_operations) {
        positive value = 0;
        
        atomic_add(&value, 5);
        fail_equals(value, 5);
        
        atomic_sub(&value, 2);
        fail_equals(value, 3);
        
        atomic_inc(&value);
        fail_equals(value, 4);
        
        atomic_dec(&value);
        fail_equals(value, 3);
        
        positive old = atomic_exchange(&value, 10);
        fail_equals(old, 3);
        fail_equals(value, 10);
        
        bool success = atomic_compare_exchange(&value, 10, 20);
        fail(success);
        fail_equals(value, 20);
        
        success = atomic_compare_exchange(&value, 10, 30);
        fail(!success);
        fail_equals(value, 20);
        
        return true;
}

test(memory_fill) {
        p8 buffer[100];
        memory_fill(buffer, 0x42, 100);
        
        for(positive i = 0; i < 100; i++) {
                fail_equals(buffer[i], 0x42);
        }
        
        memory_fill(buffer, 0, 50);

        for(positive i = 0; i < 50; i++) {
                fail_equals(buffer[i], 0);
        }

        for(positive i = 50; i < 100; i++) {
                fail_equals(buffer[i], 0x42);
        }

        return true;
}

test(memory_copy) {

        // overlapping regions
        p8 buffer[] = "1234567890";
        memory_copy(buffer + 2, buffer, 5);
        fail_equals(buffer[2], '1');
        fail_equals(buffer[6], '5');
        
        // non-overlapping regions
        /* TBD
        p8 source[] = "Hello, World!";
        p8 destination[50] = {0};
        memory_copy(destination, source, 16);
        fail_equals(string_compare(destination, source), 0);
        */

        return true;
}

test(string_length) {
        fail_equals(string_length(""), 0);
        fail_equals(string_length("a"), 1);
        fail_equals(string_length("Hello"), 5);
        fail_equals(string_length("Dawning\0Hidden"), 7);
        
        p8 buffer[100];
        memory_fill(buffer, 'A', 99);
        buffer[99] = end;
        fail_equals(string_length(buffer), 99);
        
        return true;
}

test(string_compare) {
        fail_equals(string_compare("", ""), 0);
        fail_equals(string_compare("abc", "abc"), 0);
        fail(string_compare("abc", "abd") < 0);
        fail(string_compare("abd", "abc") > 0);
        fail(string_compare("abc", "abcd") < 0);
        fail(string_compare("abcd", "abc") > 0);
        
        return true;
}

test(string_copy) {
        p8 dest[100];
        
        string_copy(dest, "Hello");
        fail_equals(string_compare(dest, "Hello"), 0);
        
        string_copy(dest, "");
        fail_equals(string_length(dest), 0);
        
        string_copy(dest, "A very long string that tests the copy function");
        fail_equals(string_length(dest), 47);
        
        return true;
}

test(string_copy_max) {
        p8 dest[100];
        memory_fill(dest, 'X', 100);
        
        string_copy_max(dest, "Hello, World!", 5);
        fail_equals(dest[5], 'X');
        fail_equals(dest[0], 'H');
        fail_equals(dest[4], 'o');
        
        return true;
}

test(string_first_of) {
        string_address result;
        
        result = string_first_of("Hello, World!", 'o');
        fail(result != null);
        fail_equals(*result, 'o');
        

        result = string_first_of("Hello, World!", 'z');
        fail_equals(result, null);
        
        result = string_first_of("Hello, World!", end);
        fail(result != null);
        fail_equals(*result, end);
        
        return true;
}

test(string_last_of) {
        string_address result;
        
        result = string_last_of("Hello, World!", 'o');
        fail(result != null);
        fail_equals(*result, 'o');
        
        result = string_last_of("Hello, World!", 'H');
        fail(result != null);
        
        result = string_last_of("Hello, World!", 'z');
        fail_equals(result, null);
        
        return true;
}

test(string_cut) {
        p8 buffer[] = "Hello, World!";
        string_address result = string_cut(buffer, ' ');
        
        fail(result != null);
        fail_equals(string_compare(buffer, "Hello,"), 0);
        fail_equals(string_compare(result, "World!"), 0);
        
        p8 buffer2[] = "NoSpaces";
        result = string_cut(buffer2, ' ');
        fail_equals(result, null);
        
        p8 buffer3[] = "End ";
        result = string_cut(buffer3, ' ');
        fail_equals(result, null);
        
        return true;
}

test(string_replace_all) {
        /*

        p8 buffer[] = "Hello, World! Hello!";
        string_replace_all(buffer, 'l', 'L');
        fail_equals(string_compare(buffer, "HeLLo, WorLd! HeLLo!"), 0);
        */        
        
        p8 buffer2[] = "aaaa";
        string_replace_all(buffer2, 'a', 'b');
        fail_equals(string_compare(buffer2, "bbbb"), 0);
        
        return true;
}

test(string_format_basic) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "Hello %s!", "World");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "Hello World!"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "%% test");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "% test"), 0);
        
        return true;
}

test(string_format_numbers) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "Positive: %p", 12345);
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "Positive: 12345"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "Bipolar: %b", -42);
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "Bipolar: -42"), 0);
        
        test_write_pos = 0;
        string_format(test_writer, "Zero: %p", 0);
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "Zero: 0"), 0);
        
        return true;
}

test(string_format_mixed) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        string_format(test_writer, "%s has %p items worth %b each", "Dawn", 5, -10);
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "Dawn has 5 items worth -10 each"), 0);
        
        return true;
}

// Path operations
test(path_basename) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        path_basename(test_writer, "/usr/bin/test");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "test"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "/usr/bin/");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "bin"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "/");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "/"), 0);
        
        test_write_pos = 0;
        path_basename(test_writer, "test.txt");
        test_write_buffer[test_write_pos] = end;
        fail_equals(string_compare(test_write_buffer, "test.txt"), 0);
        
        return true;
}

test(str_macro) {
        string_address data;
        positive length;
        
        data = str("Hello");
        fail_equals(data[0], 'H');
        fail_equals(data[1], 'e');
        
        return true;
}

test(string_end) {
        fail_equals(end, '\0');
        fail_equals(end, 0);
        
        p8 buffer[] = "Test";
        fail_equals(buffer[4], end);
        
        return true;
}

test(writer_pattern) {
        test_write_pos = 0;
        memory_fill(test_write_buffer, 0, 1000);
        
        test_writer("Hello", 5);
        fail_equals(test_write_pos, 5);
        fail_equals(string_compare(test_write_buffer, "Hello"), 0);
        
        test_writer(", ", 2);
        test_writer("World!", 0);
        fail_equals(string_compare(test_write_buffer, "Hello, World!"), 0);
        
        return true;
}


dawn_test dawn_tests[] = {
        case(type_sizes),
        case(type_ranges),
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