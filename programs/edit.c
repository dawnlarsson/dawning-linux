#include "../standard/library.c"

positive2 res;
positive2 cursor;
bool cursor_visible = false;

fn frame()
{
        res = term_size();
}

b32 main()
{
        log(str(TERM_CLEAR_SCREEN TERM_HIDE_CURSOR TERM_ALT_BUFFER TERM_RESET));

        log_flush();

        log(str("Decimal/float printing & polynomial sine wave\n\n"));

        decimal_to_string(log, PI);
        log(str("\n"));
        decimal_to_string(log, -PI);
        log(str("\n"));
        decimal_to_string(log, PI2);
        log(str("\n"));
        decimal_to_string(log, -PI2);
        log(str("\n"));

        decimal time = 0;

        while (1)
        {
                frame();

                log(str(ANSI "6;1H"));

                log(str("\nsine\n"));
                decimal_to_string(log, fast_sin(time) * 10);

                log(str("\n\ncosine\n"));
                decimal_to_string(log, fast_sin(time + PI2 / 4) * 10);

                log(str("\n\ntan\n"));
                decimal_to_string(log, fast_sin(time) / fast_sin(time + PI2 / 4));

                time += 0.00001;

                log_flush();

                // sleep(1, 1);
        }

        log(str(TERM_CLEAR_SCREEN TERM_SHOW_CURSOR TERM_MAIN_BUFFER TERM_RESET));
}