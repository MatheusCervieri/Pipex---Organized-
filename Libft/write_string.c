/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:22:51 by mvieira-          #+#    #+#             */
/*   Updated: 2022/07/26 00:18:59 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		while (str[len] != '\0')
			len += write_plus_one(str[len]);
		free(str);
	}
	else
	{
		while (str[len] != '\0')
		len += write_plus_one(str[len]);
	}
	return (len);
}
