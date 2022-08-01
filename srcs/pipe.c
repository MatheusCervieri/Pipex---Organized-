/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:48:39 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/01 22:35:04 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_program(char *cmd, char *argVec[], t_data *data)
{
	char	*envVec[] = {NULL};

	if(execve(cmd, argVec, envVec) == -1) 
		exit_program("Couldn't open the program", data);
}

int	open_file(char *file_name, t_data *data)
{
	int fd;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		exit_program("Error when open the file!", data);
	return (fd);
}
void pid_one_func(t_data *data, int in_file_fd, int fd[2])
{
	dup2(in_file_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	open_program(data->program1_path, data->input_program_parameters, data);
}

void pid_two_func(t_data *data, int out_file_fd, int fd[2])
{
	dup2(out_file_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	open_program(data->program2_path,
			data->output_program_parameters, data);
}

void	pipe_operator(t_data *data)
{
	int	fd[2];
	int	in_file_fd;
	int	out_file_fd;
	int	pid1;
	int	pid2;

	in_file_fd = open_file("./text1.txt", data);
	out_file_fd = open_file("./text2.txt", data);
	if (pipe(fd) == -1)
		exit_program("Pipe function error", data);
	pid1 = fork();
	if (pid1 < 0)
		exit_program("Fork function error", data);
	if (pid1 == 0)
		pid_one_func(data, in_file_fd, fd);		
	pid2 = fork();
	if (pid2 == 0)
		pid_two_func(data, out_file_fd, fd);
	close(in_file_fd);
	// close out_file_fd
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
