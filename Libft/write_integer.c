/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:15:06 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:54 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_integer(signed long number)
{
	int		len;
	char	*converted_nb;
	char	*decimal_chars;

	len = 0;
	if (number < 0)
	{
		write_plus_one('-');
		number = number * -1;
		len++;
	}
	decimal_chars = ft_strdup("0123456789");
	converted_nb = itoa_base(number, decimal_chars);
	len = len + write_string(converted_nb);
	free(converted_nb);
	free(decimal_chars);
	return (len);
}
