/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:06 by chustei           #+#    #+#             */
/*   Updated: 2023/05/14 18:57:20 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_get_size(char **av)
{
	int	size;

	size = 1;
	while (av[size])
		size++;
	return (size - 1);
}

void	ft_init_stacks(char **av, t_stack *stack)
{
	stack->size_a = ft_get_size(av);
	stack->size_b = 0;
	stack->a = (int *)malloc(sizeof(int) * stack->size_a);
	stack->b = (int *)malloc(sizeof(int) * stack->size_a);
}

int	*ft_stack_copy_for_sorting(int *stack, int size)
{
	int	i;
	int	*stack_copy;

	i = 0;
	stack_copy = malloc(sizeof(int) * size);
	while (i < size)
	{
		stack_copy[i] = stack[i];
		i++;
	}
	return (stack_copy);
}

void	ft_store_stack_a(char **av, t_stack *stack)
{
	int	i;
	int	j;
	int	*stack_copy;

	i = 0;
	while (av[++i])
		stack->a[i - 1] = ft_atoi(av[i]);
	stack_copy = ft_stack_copy_for_sorting(stack->a, stack->size_a);
	ft_quick_sort(stack_copy, 0, stack->size_a - 1);
	i = -1;
	while (++i < stack->size_a)
	{
		j = -1;
		while (++j < stack->size_a)
		{
			if (stack->a[i] == stack_copy[j])
			{
				stack->a[i] = j;
				break ;
			}
		}
	}
	free(stack_copy);
}

void	ft_free_stacks(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}
