/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:52:26 by chustei           #+#    #+#             */
/*   Updated: 2023/05/03 11:44:25 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/inc/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

// check_utils.c
int		ft_check_zero(char *stack_a);
int		ft_check_numeric(char **args);
int		ft_check_double(t_stack *stack);
int		ft_check_atoi(char **av);
int		ft_check_sorted(int *stack_a, int size);

// push_swap.c
void	ft_push_swap(t_stack *stack);

// push.c
void	ft_push_b(t_stack *stack);
void	ft_push_a(t_stack *stack);

// rotate.c
void	ft_rotate(int *stack, int pos, int size, char *move);

// init_and_free.c
void	ft_init_stacks(char **av, t_stack *stack);
void	ft_free_stacks(t_stack *stack);
int		ft_get_size(char **av);

#endif
