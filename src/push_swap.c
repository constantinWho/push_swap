/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:53 by chustei           #+#    #+#             */
/*   Updated: 2023/05/12 15:40:44 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	ft_sort_four(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (stack->a[0] == 0)
			ft_push_b(stack);
		else
			ft_rotate(stack->a, 1, stack->size_a, "ra");
	}
	ft_sort_three(stack);
	ft_push_a(stack);
}

void	ft_sort_five(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			ft_push_b(stack);
		else
			ft_rotate(stack->a, 1, stack->size_a, "ra");
	}
	ft_sort_three(stack);
	ft_push_a(stack);
	ft_push_a(stack);
}

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

void	ft_push_swap(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->size_a == 2)
		ft_swap(&stack->a[0], &stack->a[1]);
	if (stack->size_a == 3)
		ft_sort_three(stack);
	if (stack->size_a == 4)
		ft_sort_four(stack);
	if (stack->size_a == 5)
		ft_sort_five(stack);
	if (stack->size_a > 3)
	{
		ft_push_to_b(stack);
		ft_push_to_a(stack);
	}
}
