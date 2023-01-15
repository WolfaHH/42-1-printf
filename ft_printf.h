/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:36:04 by ngodard           #+#    #+#             */
/*   Updated: 2023/01/15 16:37:04 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_c(int c);
int	ft_s(char*s);
int	ft_u(unsigned long n, unsigned int base);
int	ft_p(void*p);
int	ft_d(int n);
int	ft_i(int n);
int	ft_x(unsigned int n);
int	ft_x_maj(unsigned int n);
int	ft_percent(void);
int	f_mode(va_list args, char mode);
int	ft_printf(const char*fmt, ...);

#endif