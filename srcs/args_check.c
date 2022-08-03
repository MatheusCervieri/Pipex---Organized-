/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:52:07 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/03 19:17:18 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_program1(t_data *data, char *program_name)
{
	int		i;
	char	*path;

	i = 0;
	while (data->env_paths[i])
	{
		path = join_bar(data->env_paths[i], program_name);
		if (access(path, F_OK) == 0)
		{
			data->program1_path = path;
			break ;
		}
		else
		{
			data->program1_path = NULL;
		}
		free(path);
		i++;
	}
}

void	find_program2(t_data *data, char *program_name)
{
	int		i;
	char	*path;

	i = 0;
	while (data->env_paths[i])
	{
		path = join_bar(data->env_paths[i], program_name);
		if (access(path, F_OK) == 0)
		{
			data->program2_path = path;
			break ;
		}
		else
		{
			data->program2_path = NULL;
		}
		free(path);
		i++;
	}
}

void	find_path_env(t_data *data, char *envp[])
{
	char	*paths;
	int		i;

	paths = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			paths = ft_strdup(envp[i] + 5);
	i++;
	}
	if (paths == NULL)
		exit_program("PATH variable not found", data);
	data->env_paths = ft_split(paths, ':');
	free(paths);
	find_program1(data, data->input_program_parameters[0]);
	find_program2(data, data->output_program_parameters[0]);
	if (data->program1_path == NULL)
		exit_program("Couldnt find the first program", data);
	if (data->program2_path == NULL)
		exit_program("Couldnt find the second program", data);
}

int open_or_create(char *file_name, t_data *data)
{
	int fd;

	fd = open(file_name, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
		exit_program("Error when open the file!", data);
	return (fd);
}


void	args_check(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc != 5)
	{
		perror("invalid number of arguments");
		exit(2);
	}
	data->output_path = argv[4];
	data->out_file_fd = open(data->output_path, O_CREAT|O_RDWR, S_IRUSR | S_IWUSR);
	if (data->out_file_fd < 0)
		exit_program("Error when open the file!", data);
	if (access(argv[1], F_OK) != 0)
	{
		exit_program("Cannot access the file", data);
	}
	data->input_path = argv[1];
	data->input_program_parameters = get_parameters(argv[2]);
	data->output_program_parameters = get_parameters(argv[3]);
	find_path_env(data, envp);
}
