#include "../standard/linux/util.c"
#include "../standard/linux/writer.c"

b32 main()
{
        write(str("quack\n"));
        writer_flush();

        return 0;
}