/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_org.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:06 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/28 20:08:40 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	array_copy(t_stack *stack_a, int *dup)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		stack_a->array[i] = dup[i];
		i++;
	}
	free(dup);
}

void	create_array(t_stack *stack_a, t_stack *stack_b, int *array)
{
	int	i;
	int	j;
	int	*dup;

	dup = malloc(sizeof(int) * stack_a->size);
	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[i] == array[j])
			{
				dup[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	array_copy(stack_a, dup);
	sorter(stack_a, stack_b);
}

void	check_organized(int *organized, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->array[i] != organized[i])
			return ;
		i++;
	}
	free(organized);
	finisher(stack_a, stack_b, "");
	exit(0);
}

void	organize_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	x;
	int	y;
	int	swap;
	int	*temp;

	x = 1;
	temp = malloc(sizeof(int) * stack_a->size);
	ft_memcpy(temp, stack_a->array, sizeof(int) * stack_a->size);
	while (x < stack_a->size)
	{
		swap = temp[x];
		y = x - 1;
		while (y >= 0 && temp[y] > swap)
		{
			temp[y + 1] = temp[y];
			y = y - 1;
		}
		temp[y + 1] = swap;
		x++;
	}
	stack_a->pos_top = 0;
	x = 0;
	check_organized(temp, stack_a, stack_b);
	create_array(stack_a, stack_b, temp);
	free(temp);
}
