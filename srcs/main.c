/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:52:03 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/03 17:28:55 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	char *teste = ft_strdup("Adasdsa \' \' dasdsaB");
	char **tokens;
	tokens = get_parameters(teste);
	ft_printf("\nArgumetns: \n");
	int i = 0;
	while (tokens[i] != NULL)
	{
		ft_printf("%s\n", tokens[i]);
		i++;
	}
	
	init_struct(&data);
	args_check(argc, argv, envp, &data);
	pipe_operator(&data, envp);
	memory_handle(&data);
	return (0);
}
