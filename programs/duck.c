#include "../standard/linux/util.c"

// TODO: just a placeholder, we are going to buffer the writes
fn write(ADDRESS data, positive length)
{
        if (length == 0)
                length = string_length(data);

        system_call_3(syscall_write, stdout, (positive)data, length);
}

// Just used for testing

b32 main()
{
        while (1)
                write(str("quack\n"));

        return 0;
}