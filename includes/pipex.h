/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:15:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/08 13:34:54 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_data
{
	char	*input_path;
	char	*output_path;
	char	**input_program_parameters;
	char	**output_program_parameters;
	char	**env_paths;
	char	*program1_path;
	char	*program2_path;
	int		in_file_fd;
	int		out_file_fd;
	int		exit_code1;
	int		exit_code2;
	int		dev_fd;
}	t_data;

void	pipe_operator(t_data *data, char *envp[]);
void	exit_program(char *error_m, t_data *data);
void	args_check(int argc, char *argv[], char *envp[], t_data *data);
char	**ft_split(char const *s, char c);
char	*join_bar(char *s1, char *s2);
void	init_struct(t_data *data);
void	memory_handle(t_data *data);
char	**get_parameters(char *parameter);
void	exit_handle(t_data *data);
void	remove_single_quotes(char ***tokens);

#endif