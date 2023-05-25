/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:20:05 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/29 16:12:48 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->pos_top;
	if (stack->pos_top >= 0)
	{
		temp = stack->array[stack->pos_top];
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[i] = temp;
	}
}

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->pos_top >= 0)
	{
		temp = stack->array[stack->pos_top + 1];
		stack->array[stack->pos_top + 1] = stack->array[stack->pos_top];
		stack->array[stack->pos_top] = temp;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b->size)
		return ;
	stack_a->pos_top--;
	stack_a->array[stack_a->pos_top] = stack_b->array[stack_b->pos_top];
	stack_b->pos_top++;
	stack_b->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (!stack_a->size)
		return ;
	i = stack_b->pos_top;
	stack_b->size++;
	if (stack_a->pos_top != 0)
	{
		while (i < stack_b->size)
		{
			swap(&stack_b->array[i], &stack_b->array[(stack_b->size)]);
			i++;
		}
	}
	stack_b->array[stack_b->pos_top] = stack_a->array[stack_a->pos_top];
	stack_a->pos_top++;
}

void	rra(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->size - 1;
	if (stack->pos_top >= 0)
	{
		temp = stack->array[i];
		while (i > stack->pos_top)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[i] = temp;
	}
}
