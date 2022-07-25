/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:41:53 by mvieira-          #+#    #+#             */
/*   Updated: 2022/06/13 19:34:44 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits_amount(int n)
{
	unsigned int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*handle_min_int(void)
{
	char	*converted_string;

	converted_string = malloc(sizeof(char) * 12);
	if (!converted_string)
		return (NULL);
	converted_string[0] = '-';
	converted_string[1] = '2';
	converted_string[2] = '1';
	converted_string[3] = '4';
	converted_string[4] = '7';
	converted_string[5] = '4';
	converted_string[6] = '8';
	converted_string[7] = '3';
	converted_string[8] = '6';
	converted_string[9] = '4';
	converted_string[10] = '8';
	converted_string[11] = '\0';
	return (converted_string);
}

char	*ft_itoa(int n)
{
	char			*converted_string;
	unsigned int	digits;
	int				number;

	number = n;
	digits = digits_amount(n);
	if (n == -2147483648)
		return (handle_min_int());
	if (n < 0)
	{
		digits = digits_amount(n * -1) + 1;
		number = number * -1;
	}
	converted_string = (char *)malloc((digits + 1) * sizeof(char));
	if (!converted_string)
		return (NULL);
	converted_string[digits] = '\0';
	while (digits > 0)
	{
		converted_string[digits-- - 1] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		converted_string[0] = '-';
	return (converted_string);
}
