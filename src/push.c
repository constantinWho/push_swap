/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:44 by chustei           #+#    #+#             */
/*   Updated: 2023/05/08 14:44:12 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void	ft_push_b(t_stack *stack)
{
	int	i;

	i = stack->size_b + 1;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = stack->a[0];
	i = 0;
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}

void	ft_push_a(t_stack *stack)
{
	int	i;

	i = stack->size_a + 1;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = stack->b[0];
	i = 0;
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->size_a++;
	stack->size_b--;
	ft_printf("pa\n");
}
