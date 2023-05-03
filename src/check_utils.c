/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:09 by chustei           #+#    #+#             */
/*   Updated: 2023/05/03 11:02:58 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_zero(char *nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_numeric(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[j] == stack->a[i])
			{
				free (stack->a);
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_atoi(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0 && ft_check_zero(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_sorted(int *stack_a, int size)
{
	int	i;
	int	curr;

	i = 0;
	while (++i < size)
	{
		curr = stack_a[i - 1];
		if (curr > stack_a[i])
			return (1);
	}
	return (0);
}
