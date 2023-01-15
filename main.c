/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:24:44 by ngodard           #+#    #+#             */
/*   Updated: 2023/01/15 16:34:42 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_mode(va_list args, char mode)
{
	int	len;

	len = 0;
	if (mode == 'c')
		len += ft_c(va_arg(args, int));
	if (mode == 's')
		len += ft_s(va_arg(args, char *));
	if (mode == 'p')
		len += ft_p(va_arg(args, char *));
	if (mode == 'd')
		len += ft_d(va_arg(args, int));
	if (mode == 'i')
		len += ft_i(va_arg(args, int));
	if (mode == 'u')
		len += ft_u(va_arg(args, unsigned int), 10);
	if (mode == 'x')
		len += ft_x(va_arg(args, unsigned int));
	if (mode == 'X')
		len += ft_x_maj(va_arg(args, unsigned int));
	if (mode == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char*fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
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
	return (len);
}

/*
# include  <stdio.h>
# include <limits.h>
int main(void)
{
	
	ft_printf("Hello world!\n");
	ft_printf("The character 'a' is %c\n", 'a');
	ft_printf("The string 'hello' is %s\n", "hello");
	ft_printf("The address of the main function is %p\n", main);
	ft_printf("%p\n", NULL);
	printf("%p", NULL);
	
	ft_printf("The decimal number 100 is %d\n", 100);
	ft_printf("%d\n", INT_MIN);
	printf("%d", INT_MIN);
	
	ft_printf("The integer -42 is %i\n", -42);
	ft_printf("The unsigned integer 100 is %u\n", 100);
	ft_printf("The hexadecimal number 100 is %x\n", 100);
	ft_printf("The uppercase hexadecimal number 100 is %X\n", 100);
	ft_printf("The percent sign is %%\n");
	
	return 0;
}
*/
