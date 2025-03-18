// Convert a positive integer to a string WIP! Broken!
// Returns a pointer to the start of the string in the provided buffer
// The buffer must be large enough to hold the result
// For uint32_t, buffer should be at least 11 characters (10 digits + null)
string_address uint_to_string(p32 value, string_address buffer)
{
        string_address step = buffer;
        step += 11;

        string_set(--step, '\0');

        do
        {
                string_set(--step, '0' + (value % 10));
                value /= 10;
        } while (value);

        return step;
}

// Convert a signed integer to a string WIP! Broken!
// Returns a pointer to the start of the string in the provided buffer
// The buffer must be large enough to hold the result
// For int32_t, buffer should be at least 12 characters (sign + 10 digits + null)
string_address int_to_string(b32 value, string_address buffer)
{
        string_address step = buffer;

        step += 12;

        string_set(--step, '\0');

        bool negative = value < 0;

        p32 abs_value = negative ? -value : value;

        do
        {
                string_set(--step, '0' + (abs_value % 10));
                abs_value /= 10;
        } while (abs_value);

        if (negative)
                string_set(--step, '-');

        return step;
}

// Convert positive to string WIP! Broken!
// Returns: address to the end of the string
string_address utoa(positive value, string_address str, p8 base)
{
        if (value == 0)
        {
                string_set(str, '0');
                string_set(str + 1, '\0');
                return str + 1;
        }

        string_address step = str;
        while (value != 0)
        {
                p8 digit = value % base;
                string_set(step++, digit < 10 ? '0' + digit : 'a' + digit - 10);
                value /= base;
        }

        string_set(step, '\0');

        string_address start = str;
        step--;

        while (start < step)
        {
                b8 temp = string_get(start);
                string_set(start++, string_get(step));
                string_set(step--, temp);
        }

        return str + strlen(str);
}

// Convert a float to string with specified precision WIP! Broken!
// Returns: address to the end of the string
string_address ftoa(decimal value, string_address str, p8 precision)
{
        if (value != value)
        {
                strcpy(str, "NaN");
                return str + 3;
        }

        bool negative = false;
        if (value < 0)
        {
                negative = true;
                value = -value;
        }

        bipolar ipart = (bipolar)value;

        decimal fpart = value - (decimal)ipart;

        string_address step = str;
        if (negative)
                string_set(step++, '-');

        if (ipart == 0)
        {
                string_set(step++, '0');
        }
        else
        {
                step = itoa(ipart, step, 10);
        }

        if (precision > 0)
        {
                string_set(step++, '.');

                while (precision--)
                {
                        fpart *= 10;
                        p8 digit = (p8)fpart;
                        string_set(step++, '0' + digit);
                        fpart -= digit;
                }
        }

        string_set(step, '\0');
        return step;
}

// Print an bipolar WIP! Broken!
fn print_bipolar(bipolar value)
{
        p8 buffer[b64_char_max + 1];
        itoa(value, buffer, 10);
        print(buffer);
}

// Print an positive WIP! Broken!
fn print_positive(positive value)
{
        p8 buffer[p64_char_max + 1];
        utoa(value, buffer, 10);
        print(buffer);
}

// Print a hexadecimal number (prefix with 0x) WIP! Broken!
fn print_hex(positive value)
{
        p8 buffer[p64_char_max + 3];
        buffer[0] = '0';
        buffer[1] = 'x';
        utoa(value, buffer + 2, 16);
        print(buffer);
}

// Print a floating-point number with given precision WIP! Broken!
fn print_decimal(decimal value, p8 precision)
{
        p8 buffer[f64_char_max + 1];
        ftoa(value, buffer, precision);
        print(buffer);
}

// Printf-like simple formatter WIP! Broken!
// Supports:
// %b - bipolar
// %p - positive
// %x - hexadecimal
// %f - float (uses precision 6)
// %c - character
// %s - string
// %% - percent sign
fn print_format(string_address format, ...)
{
        variable_arguments args;
        variable_arguments_start(args, format);

        string_address step = format;
        p8 buffer[f64_char_max + 1];

        while (string_get(step))
        {
                if (string_get(step) != '%')
                {
                        string_address start = step;
                        while (string_get(step) && string_get(step) != '%')
                                step++;

                        b8 temp = string_get(step);
                        string_set(step, '\0');
                        print(start);
                        string_set(step, temp);
                }
                else
                {
                        step++;

                        switch (string_get(step))
                        {
                        case 'b':
                        {
                                bipolar value = variable_argument(args, bipolar);
                                itoa(value, buffer, 10);
                                print(buffer);
                                break;
                        }
                        case 'p':
                        {
                                positive value = variable_argument(args, positive);
                                utoa(value, buffer, 10);
                                print(buffer);
                                break;
                        }
                        case 'x':
                        {
                                positive value = variable_argument(args, positive);
                                buffer[0] = '0';
                                buffer[1] = 'x';
                                utoa(value, buffer + 2, 16);
                                print(buffer);
                                break;
                        }
                        case 'f':
                        {
                                decimal value = variable_argument(args, decimal);
                                ftoa(value, buffer, 6);
                                print(buffer);
                                break;
                        }
                        case 'c':
                        {
                                b8 value = variable_argument(args, b32);
                                buffer[0] = value;
                                buffer[1] = '\0';
                                print(buffer);
                                break;
                        }
                        case 's':
                        {
                                string_address value = variable_argument(args, string_address);
                                print(value);
                                break;
                        }
                        case '%':
                        {
                                buffer[0] = '%';
                                buffer[1] = '\0';
                                print(buffer);
                                break;
                        }
                        default:
                                buffer[0] = '%';
                                buffer[1] = string_get(step);
                                buffer[2] = '\0';
                                print(buffer);
                                break;
                        }
                        step++;
                }
        }

        variable_arguments_end(args);
}