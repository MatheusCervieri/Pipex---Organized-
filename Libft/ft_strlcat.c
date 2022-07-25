/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:00:11 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/08 22:00:01 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	len_src;
	size_t	final_size;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size > len_dst)
		final_size = len_src + len_dst;
	else
		final_size = len_src + size;
	s = (char *) src;
	while (*s != '\0' && (len_dst + 1) < size)
	{
		dst[len_dst] = *s;
		len_dst++;
		s++;
	}
	dst[len_dst] = '\0';
	return (final_size);
}
