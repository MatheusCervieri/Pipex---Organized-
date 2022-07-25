/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:10:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:46 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_hex_upper(unsigned int number)
{
	int		len;
	char	*converted_nb;
	char	*hex_upp_chars;

	hex_upp_chars = ft_strdup("0123456789ABCDEF");
	converted_nb = itoa_base(number, hex_upp_chars);
	len = write_string(converted_nb);
	free(converted_nb);
	free(hex_upp_chars);
	return (len);
}
