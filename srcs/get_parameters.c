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
					*(*parameter) = 'A';
				*parameter = *parameter + 1;
			}
		}
		if (*(*parameter) == 39)
		{
			*parameter = *parameter + 1;
			while (*(*parameter) != 39 && *(*parameter) != '\0')
			{
				if (*(*parameter) == ' ')
					*(*parameter) = 'A';
				*parameter = *parameter + 1;
			}
		}
		*parameter = *parameter + 1;
	}
	*parameter = position;
}




void	get_parameters(char *parameter)
{
	char *teste = ft_strdup(parameter);
	char *teste2 = ft_strdup("A ' ' BDASADSA");
	change_spaces(&teste);
	change_spaces(&teste2);


	ft_printf("UHULL: \n");
	ft_printf("%s", teste);
		ft_printf("UHULL: \n");
	ft_printf("%s", teste2);
}
