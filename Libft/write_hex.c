/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:11:29 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:48 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_hex(unsigned int number)
{
	int		len;
	char	*converted_nb;
	char	*hex_chars;

	hex_chars = ft_strdup("0123456789abcdef");
	converted_nb = itoa_base(number, hex_chars);
	len = write_string(converted_nb);
	free(converted_nb);
	free(hex_chars);
	return (len);
}
