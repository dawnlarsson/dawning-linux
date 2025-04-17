typedef void(* test_case)();

typedef struct {
    const char* name;
    test_case function;
} test_list;

#define test(name) \
    void test_##name() { \
        #include "sterilize.c" \
        #include "../library.c"

test(memory_operations)
        
}

#define case(name) { #name, test_##name }

test_list tests[] = {
    case(memory_operations),
    { 0, 0 }
};