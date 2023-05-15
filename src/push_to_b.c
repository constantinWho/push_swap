/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:43:15 by chustei           #+#    #+#             */
/*   Updated: 2023/05/14 18:46:09 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_get_count(int j, int max, int ratio, t_stack *stack)
{
	int	count;

	count = 0;
	while (++j < max + 1)
	{
		if (stack->a[j] < ratio && stack->a[j] != max && \
			stack->a[j] != max - 1 && stack->a[j] != max - 2)
		{
			if (max - j > max / 2)
				ft_rotate(stack->a, j, stack->size_a, "ra");
			else
				ft_rotate(stack->a, j, stack->size_a, "rra");
			if (j == 0)
			{
				ft_push_b(stack);
				count++;
			}
			j = -1;
			break ;
		}
	}
	return (count);
}

void	ft_iteration_b(int count, int max, int ratio, t_stack *stack)
{
	int	j;
	int	i;

	i = -1;
	while (++i < max + 1)
	{
		j = -1;
		if (stack->size_a == 3)
			break ;
		count += ft_get_count(j, max, ratio, stack);
		if (count == ratio)
		{
			if (max < 150)
				ratio += 20;
			else if (max < 600)
				ratio += 45;
			i = -1;
		}
		if (stack->size_a > 3)
			j = -1;
	}
}

void	ft_push_to_b(t_stack *stack)
{
	int	max;
	int	ratio;
	int	count;

	count = 0;
	max = stack->size_a - 1;
	if (max < 50)
		ratio = 5;
	if (max < 150)
		ratio = 45;
	else if (max < 600)
		ratio = 30;
	ft_iteration_b(count, max, ratio, stack);
	if (stack->size_a == 3)
		ft_sort_three(stack);
}
