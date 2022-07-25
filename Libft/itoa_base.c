/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:58:30 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:19:11 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_converted_len(unsigned long long n, char *base_chars)
{
	unsigned int				len;
	unsigned long long			base_type;

	len = 1;
	base_type = ft_strlen(base_chars);
	while (n >= base_type)
	{
		n /= base_type;
		len++;
	}
	return (len);
}

char	*itoa_base(unsigned long long n, char *base_chars)
{
	char	*converted_str;
	int		converted_len;
	int		base_type;
	int		null_position;

	converted_len = ft_converted_len(n, base_chars);
	base_type = ft_strlen(base_chars);
	converted_str = malloc(converted_len + 1 * sizeof(char));
	if (!converted_str)
		return (NULL);
	null_position = converted_len;
	while (converted_len)
	{
		converted_len = converted_len - 1;
		converted_str[converted_len] = base_chars[n % base_type];
		n /= base_type;
	}
	converted_str[null_position] = '\0';
	return (converted_str);
}
