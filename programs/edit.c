#include "../standard/linux.c"
#include "../standard/linux/writer.c"

positive2 res;
positive2 cursor;
bool cursor_visible = false;

fn frame()
{
        res = term_size();
}

b32 main()
{
        write(str(TERM_CLEAR_SCREEN TERM_HIDE_CURSOR TERM_ALT_BUFFER TERM_RESET));

        writer_flush();

        write(str("Decimal/float printing & polynomial sine wave\n\n"));

        decimal_to_string(write, PI);
        write(str("\n"));
        decimal_to_string(write, -PI);
        write(str("\n"));
        decimal_to_string(write, PI2);
        write(str("\n"));
        decimal_to_string(write, -PI2);
        write(str("\n"));

        decimal time = 0;

        while (1)
        {
                frame();

                write(str(ANSI "6;1H"));

                write(str("\nsine\n"));
                decimal_to_string(write, fast_sin(time) * 10);

                write(str("\n\ncosine\n"));
                decimal_to_string(write, fast_sin(time + PI2 / 4) * 10);

                write(str("\n\ntan\n"));
                decimal_to_string(write, fast_sin(time) / fast_sin(time + PI2 / 4));

                time += 0.00001;

                writer_flush();

                // sleep(1, 1);
        }

        write(str(TERM_CLEAR_SCREEN TERM_SHOW_CURSOR TERM_MAIN_BUFFER TERM_RESET));
}