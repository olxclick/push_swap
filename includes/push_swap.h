/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:58:46 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/29 16:13:43 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	pos_top;
	int	size;
}		t_stack;

int		check_args(int argc, char **argv);
int		check_integer(char *str);
int		ft_check_white_spaces(char *s);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		len_dec(int n);
int		ft_isdigit(char c);
int		check_duplicate(int *array, int size);
void	ft_bzero(void *s, size_t n);
t_stack	*init_stack(int size, char **argv);
t_stack	*init_stack_b(int size);
void	*ft_calloc(size_t nmemb, size_t size);
void	destroy(t_stack *stack_a, t_stack *stack_b);
void	organize_stack(t_stack *stack_a, t_stack *stack_b);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ra(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	swap(int *s1, int *s2);
void	rra(t_stack *stack);
int		finisher(t_stack *stack_a, t_stack *b, char *error_msg);
int		max(t_stack *stack);
int		min(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	organize_stack(t_stack *stack_a, t_stack *stack_b);
void	process_action(t_stack *stack_a, t_stack *stack_b, char *action);
void	sorter(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);

#endif