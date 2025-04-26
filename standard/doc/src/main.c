// Dawning Documentation Genorator v1
#include "../../library.c"
#include "../../platform/shell.c"

#define html_style '<link rel="stylesheet" href="https://dawning.dev/runtime/u&i.css">'
#define tag(name, data, content) string_format(log, "<%s %s>%s</%s>", name, data, content, name)
#define tag_empty(name, data) string_format(log, "<%s %s/>", name, data)

fn html_push(string_address name, string_address data)
{
    if (!string_get(data))
        return string_format(log, "<%s>", name);

    string_format(log, "<%s %s>", name, data);
}

fn html_pop(string_address name)
{
    return string_format(log, "</%s>", name);
}


b32 main()
{
    dawn_shell_cd(log, "..");

    string_format(log, "<!DOCTYPE html>");
    html_push("html", "lang=en");
    html_push("head", "");
    tag_empty("meta", "charset=utf-8");
    tag_empty("meta", "name=viewport content=\"width=device-width initial-scale=1.0\"");
    tag_empty("meta", "name=description content=\"Dawning C Standard Library Documentation\"");
    html_pop("head");

    html_push("body", "");

    file lib = file_new("../library.c", FILE_READ);
    
    if(file_load(address_of lib) == null)
        log_direct(str("Failed to load library.c\n"));

    //log(lib.data, 30);

    html_pop("body");
    html_pop("html");

    log_flush();
}