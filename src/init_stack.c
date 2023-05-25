/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:58:32 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/29 15:57:39 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int size, char **argv)
{
	t_stack	*stack;
	int		i;
	int		j;
	int		number;

	j = 0;
	i = 0;
	stack = malloc(sizeof(t_stack));
	stack->array = malloc(sizeof(int) * size);
	stack->pos_top = 0;
	stack->size = size;
	while (argv[++i])
	{
		number = ft_atoi(argv[i]);
		stack->array[j] = number;
		j++;
	}
	return (stack);
}

t_stack	*init_stack_b(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->size = 0;
	stack->array = ft_calloc(sizeof(int), size);
	stack->pos_top = 0;
	return (stack);
}
