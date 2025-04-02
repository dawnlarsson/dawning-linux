// simple bufferd writer for linux, buffred to the size of a kernel page

#define MAX_INPUT 4096

p8 buffer[MAX_INPUT];
positive buffer_length;

p8 writer_buffer[MAX_INPUT];
positive writer_buffer_length;

fn writer_flush()
{
        if (writer_buffer_length == 0)
                return;

        system_call_3(syscall(write), stdout, (positive)writer_buffer, writer_buffer_length);

        writer_buffer_length = 0;
}

fn write(ADDRESS data, positive length)
{
        if (length == 0)
                length = string_length(data);

        if (length + writer_buffer_length > MAX_INPUT)
                writer_flush();

        if (length > MAX_INPUT)
        {
                system_call_3(syscall(write), stdout, (positive)data, length);
                return;
        }

        memory_copy(writer_buffer + writer_buffer_length, data, length);
        writer_buffer_length += length;
}