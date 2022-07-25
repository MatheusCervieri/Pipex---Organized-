/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:13:22 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/14 16:23:58 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			slen;
	size_t			max_len_possible;
	unsigned int	i;

	slen = ft_strlen(s);
	max_len_possible = slen - start;
	if (start >= slen)
		return (ft_strdup(""));
	if (max_len_possible <= len)
		substr = malloc(max_len_possible * sizeof(char) + 1);
	else
		substr = malloc(len * sizeof(char) + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
