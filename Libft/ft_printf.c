/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:08:18 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:19:25 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			len;

	len = 0;
	if (!fmt)
		return (0);
	va_start(args, fmt);
	len = write_input(fmt, args);
	va_end(args);
	return (len);
}
