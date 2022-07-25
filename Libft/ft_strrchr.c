/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:57:32 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/14 16:11:31 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*initial_value;
	int			i;

	initial_value = s;
	i = ft_strlen(s);
	s = (s + i);
	while (s != initial_value && (unsigned char)c != *s)
	{
		s--;
	}
	if ((unsigned char)c == *s)
	{
		return ((char *) s);
	}
	return (0);
}
