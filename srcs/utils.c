/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:11:54 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/01 22:14:35 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_bar(char *s1, char *s2)
{
	size_t	newstrlen;
	char	*newstr;
	char	*newstrfirstposition;

	newstrlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(newstrlen * sizeof(char) + 2);
	if (!newstr)
		return (NULL);
	newstrfirstposition = newstr;
	while (*s1 != '\0')
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	*newstr = '/';
	newstr++;
	while (*s2 != '\0')
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';
	return (newstrfirstposition);
}
