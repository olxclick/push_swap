/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:54:38 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/29 16:11:56 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	i = -1;
	max_bits = 0;
	max_num = stack_a->size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stack_a->size)
		{
			if ((stack_a->array[stack_a->pos_top] >> i & 1) == 1)
				process_action(stack_a, stack_b, "ra");
			else
				process_action(stack_a, stack_b, "pb");
		}
		while (stack_b->size > 0)
			process_action(stack_a, stack_b, "pa");
		if (stack_b->size == 0)
			stack_b->pos_top = 0;
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[stack_a->pos_top] < stack_a->array[stack_a->pos_top + 1]
		&& stack_a->array[stack_a->pos_top] < \
		stack_a->array[stack_a->pos_top + 2]
		&& stack_a->array[stack_a->pos_top + 1] == max(stack_a))
	{
		process_action(stack_a, stack_b, "sa");
		process_action(stack_a, stack_b, "ra");
	}
	else if (stack_a->array[stack_a->pos_top + 2] == max(stack_a)
		&& stack_a->array[stack_a->pos_top + 1] == min(stack_a))
		process_action(stack_a, stack_b, "sa");
	else if (stack_a->array[stack_a->pos_top] == max(stack_a)
		&& stack_a->array[stack_a->pos_top + 2] == min(stack_a))
	{
		process_action(stack_a, stack_b, "sa");
		process_action(stack_a, stack_b, "rra");
	}
	else if (stack_a->array[stack_a->pos_top] == max(stack_a)
		&& stack_a->array[stack_a->pos_top + 1] == min(stack_a))
		process_action(stack_a, stack_b, "ra");
	else if (stack_a->array[stack_a->pos_top + 1] == max(stack_a)
		&& stack_a->array[stack_a->pos_top + 2] == min(stack_a))
		process_action(stack_a, stack_b, "rra");
}

void	sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size != 2)
	{
		if (stack_a->array[stack_a->pos_top] == 0 || \
		stack_a->array[stack_a->pos_top] == 1)
			process_action(stack_a, stack_b, "pb");
		else
			process_action(stack_a, stack_b, "ra");
	}
	sort_small(stack_a, stack_b);
	while (stack_b->size > 0)
		process_action(stack_a, stack_b, "pa");
	if (stack_a->array[stack_a->pos_top] > stack_a->array[stack_a->pos_top + 1])
		process_action(stack_a, stack_b, "sa");
}

void	sorter(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_small(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_medium(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

void	process_action(t_stack *stack_a, t_stack *stack_b, char *action)
{
	if (action[0] == 'r' && action[1] == 'a')
	{
		ra(stack_a);
		ft_printf("ra\n");
	}
	else if (action[0] == 'p' && action[1] == 'b')
	{
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else if (action[0] == 's' && action[1] == 'a')
	{
		sa(stack_a);
		ft_printf("sa\n");
	}
	else if (action[0] == 'p' && action[1] == 'a')
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else if (action[0] == 'r' && action[1] == 'r')
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
}
