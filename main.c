/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:58:33 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/30 14:19:17 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc - 1, argv);
	b = init_stack_b(argc - 1);
	if (argc < 3)
		return (finisher(a, b, ""));
	if (!check_args(argc, argv))
		return (finisher(a, b, "Error\n"));
	organize_stack(a, b);
	finisher(a, b, "");
}
