/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:14:46 by chustei           #+#    #+#             */
/*   Updated: 2023/05/10 13:05:01 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_stack_copy(int *stack, int *new_stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		new_stack[i] = stack[i];
		i++;
	}
}

void	ft_rotate(int *stack, int pos, int size, char *move)
{
	int		*new_stack;
	int		i;
	int		rest;

	i = 0;
	rest = 0;
	new_stack = (int *)malloc(sizeof(int) * size);
	while (pos < size)
	{
		new_stack[i] = stack[pos];
		i++;
		pos++;
		if (ft_strncmp(move, "rra", 3) == 0)
			ft_printf("%s\n", move);
	}
	while (i < size)
	{
		new_stack[i] = stack[rest];
		i++;
		rest++;
		if (ft_strncmp(move, "ra", 2) == 0)
			ft_printf("%s\n", move);
	}
	ft_stack_copy(new_stack, stack, size);
	free(new_stack);
}
