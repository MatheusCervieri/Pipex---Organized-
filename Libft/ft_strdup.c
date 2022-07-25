/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:53:34 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/07 00:54:39 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	char	*newstrp;

	newstr = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (newstr == NULL)
		return (NULL);
	newstrp = newstr;
	while (*s != '\0')
	{
		*newstr = *s;
		newstr++;
		s++;
	}
	*newstr = '\0';
	return (newstrp);
}
