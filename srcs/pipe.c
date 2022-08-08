/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:48:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 15:57:30 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file_name)
{
	int	fd;

	if (file_name != NULL)
	{
		fd = open(file_name, O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
		return (fd);
	}
	return (-1);
}

void	pid_one_func(t_data *data, int in_file_fd, int fd[2], char *envp[])
{
	if (in_file_fd != -1)
	{
		dup2(in_file_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(data->program1_path, data->input_program_parameters, envp);
	}
	else
	{
		data->dev_fd = open("/dev/null", O_WRONLY);
		dup2(data->dev_fd, STDOUT_FILENO);
		dup2(fd[1], data->dev_fd);
		close(fd[0]);
		close(data->dev_fd);
		execve(data->program1_path, data->input_program_parameters, envp);
	}
}

void	pid_two_func(t_data *data, int out_file_fd, int fd[2], char *envp[])
{
	dup2(out_file_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (data->program2_path != NULL)
		execve(data->program2_path, data->output_program_parameters, envp);
}

int	create_process1(t_data *data, int fd[2], int in_file_fd, char *envp[])
{
	int	pid1;
	int	dev_null;

	pid1 = -1;
	if (data->program1_path == NULL || data->input_path == NULL)
	{
		dev_null = open("/dev/null", O_WRONLY);
		dup2(dev_null, fd[1]);
		close(dev_null);
	}
	else
	{
		pid1 = fork();
		if (pid1 < 0)
			exit_program("Fork function error", data);
		if (pid1 == 0)
			pid_one_func(data, in_file_fd, fd, envp);
	}
	return (pid1);
}

void	pipe_operator(t_data *data, char *envp[])
{
	int	fd[2];
	int	in_file_fd;
	int	pid[2];
	int	status;
	int	status2;

	in_file_fd = open_file(data->input_path);
	if (pipe(fd) == -1)
		exit_program("Pipe function error", data);
	pid[0] = create_process1(data, fd, in_file_fd, envp);
	pid[1] = fork();
	if (pid[1] == 0)
		pid_two_func(data, data->out_file_fd, fd, envp);
	if (in_file_fd != -1)
		close(in_file_fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status, 0);
	data->exit_code1 = WEXITSTATUS(status);
	waitpid(pid[1], &status2, 0);
	data->exit_code2 = WEXITSTATUS(status2);
}
