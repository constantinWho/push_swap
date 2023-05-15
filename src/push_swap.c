/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:53 by chustei           #+#    #+#             */
/*   Updated: 2023/05/14 18:50:24 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_min_pos(int *stack_a, int size)
{
	int	i;
	int	pos;
	int	min;

	pos = 0;
	min = stack_a[0];
	i = 0;
	while (++i < size)
	{
		if (stack_a[i] < min)
		{
			min = stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	ft_printf("sa\n");
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] < stack->a[2])
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_rotate(stack->a, 2, stack->size_a, "rra");
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 1, stack->size_a, "ra");
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
			stack->a[0] < stack->a[2])
	{
		ft_rotate(stack->a, 2, stack->size_a, "rra");
		ft_swap(&stack->a[0], &stack->a[1]);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
		stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 2, stack->size_a, "rra");
}

void	ft_push_swap_small(t_stack *stack)
{
	int	min_pos;

	min_pos = ft_min_pos(stack->a, stack->size_a);
	if (stack->size_a - min_pos > stack->size_a / 2)
		ft_rotate(stack->a, min_pos, stack->size_a, "ra");
	else
		ft_rotate(stack->a, min_pos, stack->size_a, "rra");
	if (ft_check_sorted(stack->a, stack->size_a) == 1)
		ft_push_b(stack);
	if (ft_check_sorted(stack->a, stack->size_a) == 1)
		ft_push_swap(stack);
	if (stack->size_b > 0)
		ft_push_a(stack);
}

void	ft_push_swap(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->size_a == 2)
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (stack->size_a == 3)
		ft_sort_three(stack);
	else if (stack->size_a > 3 && stack->size_a <= 20)
		ft_push_swap_small(stack);
	else if (stack->size_a > 20)
	{
		ft_push_to_b(stack);
		ft_push_to_a(stack);
	}
}
