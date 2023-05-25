/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:24:57 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/29 16:12:36 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	finisher(t_stack *stack_a, t_stack *stack_b, char *error_msg)
{
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	destroy(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void	destroy(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array)
		free(stack_a->array);
	if (stack_a)
		free(stack_a);
	if (stack_b->array)
		free(stack_b->array);
	if (stack_b)
		free(stack_b);
}
