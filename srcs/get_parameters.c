#include "pipex.h"



static void	remove_quotes(char ***tokens)
{
	int	i;
	int	j;

	i = 0;
	while ((*tokens)[i] != NULL)
	{
		if ((*tokens)[i][ft_strlen((*tokens)[i]) - 1] == '\'')
			(*tokens)[i][ft_strlen((*tokens)[i]) - 1] = '\0';
		if ((*tokens)[i][0] == '\'')
		{
			j = 0;
			while ((*tokens)[i][++j])
			(*tokens)[i][j - 1] = (*tokens)[i][j];
			(*tokens)[i][j - 1] = '\0';
		}
		i++;
	}
	i = 0;
	while ((*tokens)[i] != NULL)
	{
		if ((*tokens)[i][ft_strlen((*tokens)[i]) - 1] == '\"')
			(*tokens)[i][ft_strlen((*tokens)[i]) - 1] = '\0';
		if ((*tokens)[i][0] == '\"')
		{
			j = 0;
			while ((*tokens)[i][++j])
			(*tokens)[i][j - 1] = (*tokens)[i][j];
			(*tokens)[i][j - 1] = '\0';
		}
		i++;
	}
}





void	change_spaces(char **parameter)
{
	char	*position;

	position = *parameter;
	while (*(*parameter) != '\0')
	{
		if (*(*parameter) == 34)
		{
			*parameter = *parameter + 1;
			while (*(*parameter) != 34 && *(*parameter) != '\0')
			{
				if (*(*parameter) == ' ')
					*(*parameter) = 1;
				*parameter = *parameter + 1;
			}
		}
		if (*(*parameter) == 39)
		{
			*parameter = *parameter + 1;
			while (*(*parameter) != 39 && *(*parameter) != '\0')
			{
				if (*(*parameter) == ' ')
					*(*parameter) = 1;
				*parameter = *parameter + 1;
			}
		}
		*parameter = *parameter + 1;
	}
	*parameter = position;
}


void revert_spaces(char ***tokens)
{
	int	i;
	int	j;

	i = 0;
	while ((*tokens)[i] != NULL)
	{
		j = 0;
		while ((*tokens)[i][j])
		{
			if ((*tokens)[i][j] == 1)
				(*tokens)[i][j] = ' ';
			j++;
		}
		i++;
	}
}

char	**get_parameters(char *parameter)
{
	char	**tokens;
	change_spaces(&parameter);
	tokens = ft_split(parameter, ' '); 
	revert_spaces(&tokens);
	remove_quotes(&tokens);
	return (tokens);
}
