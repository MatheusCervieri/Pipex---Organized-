/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:48:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 13:22:37 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_program(char *cmd, char *argVec[], char *envp[], t_data *data)
{
	if (execve(cmd, argVec, envp) == -1)
	{
		dup2(data->dev_fd, STDOUT_FILENO);
	}
}

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
		open_program(data->program1_path, data->input_program_parameters, envp, data);
	}
	else
	{
		dup2(data->dev_fd, STDOUT_FILENO);
		dup2(fd[1], data->dev_fd);
		close(fd[0]);
		close(data->dev_fd);
		open_program(data->program1_path, data->input_program_parameters, envp, data);
	}
}

void pid_two_func(t_data *data, int out_file_fd, int fd[2], char *envp[])
{
	
	dup2(out_file_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (data->program2_path != NULL)
		open_program(data->program2_path, data->output_program_parameters, envp, data);
}

void	pipe_operator(t_data *data, char *envp[])
{
	int	fd[2];
	int in_file_fd;
	int	pid1;
	int	pid2;
	
	pid1 = -1;
	in_file_fd = open_file(data->input_path);
	if (pipe(fd) == -1)
		exit_program("Pipe function error", data);
	if (data->program1_path == NULL || data->input_path == NULL)
	{
		int devnull = open("/dev/null", O_WRONLY);
		dup2(devnull, fd[1]);
	}
	else
	{
	pid1 = fork();
	if (pid1 < 0)
		exit_program("Fork function error", data);
	if (pid1 == 0)
		pid_one_func(data, in_file_fd, fd, envp);
	}
	
	pid2 = fork();
	if (pid2 == 0)
		pid_two_func(data, data->out_file_fd, fd, envp);
	if (in_file_fd != -1)
		close(in_file_fd);
	// close out_file_fd
	int status;
	int status2;
	
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	data->exit_code1 = WEXITSTATUS(status);
	waitpid(pid2, &status2, 0);
	data->exit_code2 = WEXITSTATUS(status2);
}
