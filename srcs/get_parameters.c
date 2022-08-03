#include "pipex.h"



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



void	get_parameters(char *parameter)
{
	char *teste = ft_strdup(parameter);
	char *teste2 = ft_strdup("A ' ' BDASADSA");
	char **tokens;
	change_spaces(&teste);
	change_spaces(&teste2);

	tokens = ft_split(teste2, ' '); 
	revert_spaces(&tokens);
	ft_printf("\nArgumetns: \n");
	int i = 0;
	while (tokens[i] != NULL)
	{
		ft_printf("%s\n", tokens[i]);
		i++;
	}
}
