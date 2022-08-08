/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:09:27 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 13:35:29 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_data *data)
{
	data->input_program_parameters = NULL;
	data->output_program_parameters = NULL;
	data->env_paths = NULL;
	data->program1_path = NULL;
	data->program2_path = NULL;
	data->dev_fd = -5;
}
