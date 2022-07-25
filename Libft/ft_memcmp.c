/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:49:27 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/13 18:21:32 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1char;
	unsigned char	*s2char;
	size_t			i;

	s1char = (unsigned char *) s1;
	s2char = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1char[i] != s2char[i])
			return (s1char[i] - s2char[i]);
		i++;
	}
	return (0);
}
