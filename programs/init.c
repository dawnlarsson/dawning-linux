#include "../library/standard.c"

u32 main()
{
        print("Hello, World!\n");
        print("TODO: Actually make a distro now... lmao...\n");

        while (1)
        {
                system_call_1(syscall_nanosleep, (bipolar){0, 500000});
        }

        return 0;
}