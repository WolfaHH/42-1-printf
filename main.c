
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int ft_c(int c)
{
    return write(1, &c, 1);
}

int ft_s(char* s)
{
    int len = 0;
    if (s != NULL)
    {
        while (*s)
        {
            len += write(1, s, 1);
            s++;
        }
    }
    else
    {
        len += write(1, "(null)", 6);
    }
    return len;
}

int ft_u(unsigned long n, unsigned int base)
{
    int len = 0;
    if (n >= base)
    {
        len += ft_u(n / base, base);
    }
    char c = (n % base);
    if (c < 10)
    {
        c += '0';
    }
    else
    {
        c += 'a' - 10;
    }
    len += write(1, &c, 1);
    return len;
}

int ft_p(void* p)
{
    int len = 0;
    if (p == NULL) {
        len += write(1, "(null)", 6);
        return len;
    }
    len += write(1, "0x", 2);
    len += ft_u((unsigned long)p, 16);
    return len;
}


int ft_d(int n)
{
    int len = 0;
    if (n < 0)
    {
        len += write(1, "-", 1);
        n *= -1;
    }
    if (n >= 10)
    {
        len += ft_d(n / 10);
    }
    char c = n % 10 + '0';
    len += write(1, &c, 1);
    return len;
}

int ft_i(int n)
{
    return ft_d(n);
}

int ft_x(unsigned int n)
{
    return ft_u(n, 16);
}

int ft_X(unsigned int n)
{
    int len = 0;
    if (n >= 16)
    {
        len += ft_X(n / 16);
    }
    char c = n % 16;
    if (c < 10)
    {
        c += '0';
    }
    else
    {
        c += 'A' - 10;
    }
    len += write(1, &c, 1);
    return len;
}

int ft_percent(void)
{
    return write(1, "%", 1);
}



int f_mode(va_list args, char mode)
{
    int len = 0;
    if (mode == 'c')
        len += ft_c(va_arg(args, int));
    if (mode == 's')
        len += ft_s(va_arg(args, char*));
    if (mode == 'p')
        len += ft_p(va_arg(args, char*));
    if (mode == 'd')
        len += ft_d(va_arg(args, int));
    if (mode == 'i')
        len += ft_i(va_arg(args, int));
    if (mode == 'u')
        len += ft_u(va_arg(args, unsigned int), 10);
    if (mode == 'x')
        len += ft_x(va_arg(args, unsigned int));
    if (mode == 'X')
        len += ft_X(va_arg(args, unsigned int));
    if (mode == '%')
        len += ft_percent();
    return len;
}

int ft_printf(char* fmt, ...)
{
    int len = 0;
    va_list args;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            len += f_mode(args, *fmt);
        }
        else
        {
            len += write(1, fmt, 1);
        }
        fmt++;
    }
    va_end(args);
    return len;
}


/*
int main(void)
{
    ft_printf("Hello world!\n");
    ft_printf("The character 'a' is %c\n", 'a');
    ft_printf("The string 'hello' is %s\n", "hello");
    ft_printf("The address of the main function is %p\n", main);
    ft_printf("The decimal number 100 is %d\n", 100);
    ft_printf("The integer -42 is %i\n", -42);
    ft_printf("The unsigned integer 100 is %u\n", 100);
    ft_printf("The hexadecimal number 100 is %x\n", 100);
    ft_printf("The uppercase hexadecimal number 100 is %X\n", 100);
    ft_printf("The percent sign is %%\n");
    return 0;
}
*/















/*



#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int     ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
        ft_putchar(s[i++]);
    return (i);
}

int     ft_putnbr_base(unsigned int n, char *base)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(base);
    if (n >= (unsigned int)len)
        i += ft_putnbr_base(n / len, base);
    ft_putchar(base[n % len]);
    return (i + 1);
}

int     ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                count += ft_putstr(va_arg(args, char*));
            else if (format[i] == 'p')
                count += ft_putstr("0x") + ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
            else if (format[i] == 'd' || format[i] == 'i')
                count += ft_putnbr_base(va_arg(args, int), "0123456789");
            else if (format[i] == 'u')
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
            else if (format[i] == 'x')
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
            else if (format[i] == 'X')
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
            else if (format[i] == '%')
                count += ft_putchar('%');
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}



#include <stdio.h>

int     main(void)
{
    int count;

    count = ft_printf("Test ft_printf: %c %s %p %d %i %u %x %X %%\n", 'A', "Hello world!", (void*)12345, 12345, 12345, 12345, 12345, 12345);
    printf("ft_printf returned %d\n", count);
    return (0);
}

*/