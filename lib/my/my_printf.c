/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** reproduce the printf function
*/

#include "my.h"
#include <stdarg.h>

void handle_print_three(const char *format, va_list aq, int i, int *ignore_char)
{
    switch (format[i]) {
    case 'S':
        print_non_printable(va_arg(aq, char *));
        break;
    case 'x':
        my_putstr(my_strlowcase(uint_to_hex(va_arg(aq, unsigned int))));
        break;
    case 'X':
        my_putstr(uint_to_hex(va_arg(aq, unsigned int)));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        break;
    }
}

void handle_print_two(const char *format, va_list aq, int i, int *ignore_char)
{
    void *pointer;

    switch (format[i]) {
        case 'd':
        case 'i':
            my_put_nbr(va_arg(aq, int));
            break;
        case 'p':
            pointer = va_arg(aq, void *);
            my_putstr("0x");
            my_putstr(my_strlowcase(long_to_hex((long)&pointer)));
            break;
        case 'b':
            my_putstr(int_to_binary(va_arg(aq, unsigned int)));
            break;
        default:
            handle_print_three(format, aq, i, ignore_char);
            break;
    }
}

void handle_print(const char *format, va_list aq, int i, int *ignore_char)
{
    switch (format[i]) {
        case 'c':
            my_putchar((char)va_arg(aq, int));
            break;
        case 's':
            my_putstr(va_arg(aq, char *));
            break;
        case 'l':
            if (format[i + 1] == 'd') {
                *ignore_char = 2;
                my_put_long(va_arg(aq, long));
            }
            break;
        default:
            handle_print_two(format, aq, i, ignore_char);
            break;
    }
}

int my_printf(const char *format, ...)
{
    va_list aq;
    int ignore_char = 0;

    va_start(aq, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            handle_print(format, aq, i, &ignore_char);
        } else if (ignore_char == 0) {
            my_putchar(format[i]);
        }
        if (ignore_char > 0) {
            ignore_char--;
        }
    }
    va_end(aq);
}