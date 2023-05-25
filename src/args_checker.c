/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:03:36 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/21 16:48:57 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(int argc, char **argv)
{
	int	j;
	int	i;
	int	*array;
	int	res;

	j = 0;
	i = 0;
	res = 1;
	array = malloc(sizeof(int) * argc - 1);
	while (argv[++j])
	{
		if (!check_integer(argv[j]))
			res = 0;
		array[i] = ft_atoi(argv[j]);
		i++;
	}
	if (!check_duplicate(array, argc - 1))
		res = 0;
	free(array);
	return (res);
}

int	check_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_strlen(str) != len_dec(ft_atoi(str)))
		return (0);
	return (1);
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	check_duplicate(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
