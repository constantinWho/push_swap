/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:48:56 by chustei           #+#    #+#             */
/*   Updated: 2023/05/14 18:50:32 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_iteration_a(int j, int i, int max, t_stack *stack)
{
	while (++j < max + 1)
	{
		i = -1;
		while (++i < stack->size_b)
		{
			if (stack->b[i] == max)
			{
				if (max - i > max / 2)
					ft_rotate(stack->b, i, stack->size_b, "rb");
				else
					ft_rotate(stack->b, i, stack->size_b, "rrb");
				if (i == 0)
				{
					ft_push_a(stack);
					max--;
					i = -1;
				}
				break ;
			}
		}
		if (stack->size_b != 0)
			j = -1;
	}
}

void	ft_push_to_a(t_stack *stack)
{
	int	i;
	int	j;
	int	max;

	max = stack->a[0] - 1;
	j = -1;
	i = -1;
	ft_iteration_a(j, i, max, stack);
}
