// Dawning Documentation Genorator v1
#include "../../library.c"
#include "../../platform/shell.c"

#define html_style '<link rel="stylesheet" href="https://dawning.dev/runtime/u&i.css">'

fn html_tag_open(writer write, string_address name, string_address data)
{
        string_format(write, "<%s %s>", name, data);
}

fn html_tag_close(writer write, string_address name)
{
        string_format(write, "</%s>\n", name);
}

fn html_tag(writer write, string_address name, string_address data, string_address content)
{
        html_tag_open(write, name, data);
        write(content, 0);
        html_tag_close(write, name);
}

b32 main()
{
        p8 cwd[4096];
        system_call_2(syscall(getcwd), (positive)cwd, 4096);

        string_format(log, TERM_BOLD "Generating docs  %s\n" TERM_RESET, cwd);

        core_mkdir(log, "docs");

        string_format(log, "Generating index.html\n");
        core_touch(log, "docs/index.html");
        

        log_flush();
}