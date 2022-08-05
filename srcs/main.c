/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:52:03 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/05 11:34:03 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	init_struct(&data);
	args_check(argc, argv, envp, &data);
	pipe_operator(&data, envp);
	memory_handle(&data);
	if (data.program2_path == NULL)
		exit(127);
	return (0);
}
