/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:39:55 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/13 17:53:01 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*allocated_memory;
	int		over_handling;

	over_handling = nelem * elsize;
	if (nelem != 0 && over_handling / nelem != elsize)
		return (NULL);
	allocated_memory = (void *) malloc (nelem * elsize);
	if (allocated_memory == NULL)
		return (NULL);
	ft_memset(allocated_memory, 0, nelem * elsize);
	return (allocated_memory);
}
