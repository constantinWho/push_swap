/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:09 by chustei           #+#    #+#             */
/*   Updated: 2023/04/26 13:23:50 by chustei          ###   ########.fr       */
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

int	ft_check_double(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[j] == nums[i])
			{
				free (nums);
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

void	ft_check_output(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%i ", nums[i++]);
	ft_printf("\n");
	quicksort(nums, 0, size - 1);
	i = 0;
	while (i < size)
		ft_printf("%i ", nums[i++]);
	ft_printf("\n");
}
