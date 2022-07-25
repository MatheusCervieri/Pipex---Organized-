/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:24:09 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:19:02 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_unsigned_integer(unsigned int number)
{
	int		len;
	char	*number_str;
	char	*decimal_chars;

	decimal_chars = ft_strdup("0123456789");
	number_str = itoa_base(number, decimal_chars);
	len = write_string(number_str);
	free(number_str);
	free(decimal_chars);
	return (len);
}
