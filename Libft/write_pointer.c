/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:19:58 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:56 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_pointer(void *ptr)
{
	int					len;
	char				*string;
	char				*pre_str;
	unsigned long int	address;
	char				*hex_chars;

	address = (unsigned long int)ptr;
	if (address != 0)
	{
		pre_str = ft_strdup("0x");
		hex_chars = ft_strdup("0123456789abcdef");
		len = write_string(pre_str);
		string = itoa_base(address, hex_chars);
		len = len + write_string(string);
		free(string);
		free(pre_str);
		free(hex_chars);
	}
	else
	{
		pre_str = ft_strdup("(nil)");
		len = write_string(pre_str);
		free(pre_str);
	}
	return (len);
}
