/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:25:56 by ngodard           #+#    #+#             */
/*   Updated: 2023/01/15 16:32:00 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_s(char*s)
{
	int	len;

	len = 0;
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
	return (len);
}

int	ft_u(unsigned long n, unsigned int base)
{
	int		len;
	char	c;

	len = 0;
	if (n >= base)
	{
		len += ft_u(n / base, base);
	}
	c = (n % base);
	if (c < 10)
	{
		c += '0';
	}
	else
	{
		c += 'a' - 10;
	}
	len += write(1, &c, 1);
	return (len);
}

int	ft_p(void*p)
{
	int	len;

	len = 0;
	if (p == NULL)
	{
		len += write(1, "0x0", 3);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_u((unsigned long)p, 16);
	return (len);
}
