/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:06 by chustei           #+#    #+#             */
/*   Updated: 2023/05/03 18:52:25 by chustei          ###   ########.fr       */
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

void	ft_free_stacks(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}
