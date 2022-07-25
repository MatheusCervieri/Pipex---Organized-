/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:01:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/07 01:03:06 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapistr;

	i = 0;
	mapistr = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!mapistr)
		return (NULL);
	while (s[i] != '\0')
	{
		mapistr[i] = f(i, s[i]);
		i++;
	}
	mapistr[i] = '\0';
	return (mapistr);
}
