/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:13:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:52 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_parameter(int c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

static int	write_parameter(int c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = write_plus_one(va_arg(args, int));
	if (c == 's')
		len = write_string(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		len = write_integer(va_arg(args, signed int));
	if (c == 'u')
		len = write_unsigned_integer(va_arg(args, unsigned int));
	if (c == 'x')
		len = write_hex(va_arg(args, unsigned int));
	if (c == 'X')
		len = write_hex_upper(va_arg(args, unsigned int));
	if (c == '%')
		len = write_plus_one(c);
	if (c == 'p')
		len = write_pointer(va_arg(args, void *));
	return (len);
}

int	write_input(const char *str, va_list args)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != '%')
			len = len + write_plus_one(*str);
		else if ((*str == '%') && (*(str + 1)))
		{
			str++;
			if (is_parameter(*str))
				len = len + write_parameter(*str, args);
			else if (*str)
				len = len + write_plus_one(*str);
		}
		str++;
	}
	return (len);
}
