/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:15:31 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 15:57:41 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	remove_single_quotes(char ***tokens)
{
	int	i;
	int	j;

	i = 0;
	while ((*tokens)[i] != NULL)
	{
		if ((*tokens)[i][ft_strlen((*tokens)[i]) - 1] == '\'')
			(*tokens)[i][ft_strlen((*tokens)[i]) - 1] = '\0';
		if ((*tokens)[i][0] == '\'')
		{
			j = 0;
			while ((*tokens)[i][++j])
			(*tokens)[i][j - 1] = (*tokens)[i][j];
			(*tokens)[i][j - 1] = '\0';
		}
		i++;
	}
}
