/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:25:48 by ngodard           #+#    #+#             */
/*   Updated: 2023/01/15 16:35:36 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d(int n)
{
	int		len;
	char	c;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_d(n / 10);
	}
	c = n % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_i(int n)
{
	return (ft_d(n));
}

int	ft_x(unsigned int n)
{
	return (ft_u(n, 16));
}

int	ft_x_maj(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 16)
	{
		len += ft_x_maj(n / 16);
	}
	c = n % 16;
	if (c < 10)
	{
		c += '0';
	}
	else
	{
		c += 'A' - 10;
	}
	len += write(1, &c, 1);
	return (len);
}

int	ft_percent(void)
{
	return (write(1, "%", 1));
}
