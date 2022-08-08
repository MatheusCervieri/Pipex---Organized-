/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:58:52 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 15:53:54 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data_input_output(t_data *data)
{
	int	i;

	i = 0;
	if (data->input_program_parameters != NULL)
	{
		while (data->input_program_parameters[i])
		{
			free(data->input_program_parameters[i]);
			i++;
		}
		free(data->input_program_parameters);
	}
	i = 0;
	if (data->output_program_parameters != NULL)
	{
		while (data->output_program_parameters[i])
		{
			free(data->output_program_parameters[i]);
			i++;
		}
		free(data->output_program_parameters);
	}
}

void	memory_handle(t_data *data)
{	
	int	i;

	free_data_input_output(data);
	if (data->env_paths != NULL)
	{
		i = 0;
		while (data->env_paths[i])
		{
			free(data->env_paths[i]);
			i++;
		}
		free(data->env_paths);
	}
	if (data->program1_path != NULL)
		free(data->program1_path);
	if (data->program2_path != NULL)
		free(data->program2_path);
}

void	exit_program(char *error_m, t_data *data)
{
	if (data->out_file_fd != -1)
		close(data->out_file_fd);
	memory_handle(data);
	perror(error_m);
	if (data->program2_path == NULL)
		exit(127);
	if (data->exit_code1 == 0 && data->exit_code2 == 85)
		exit(0);
	if (data->exit_code1 == 1 && data->exit_code2 == 85)
		exit(0);
	exit(0);
}

void	exit_handle(t_data *data)
{
	if (data->out_file_fd != -1)
		close(data->out_file_fd);
	memory_handle(data);
	if (data->program2_path == NULL)
		exit(127);
	if (data->exit_code1 == 0 && data->exit_code2 >= 85)
		exit(0);
	if (data->exit_code1 == 1 && data->exit_code2 >= 1)
		exit(1);
	exit(0);
}
