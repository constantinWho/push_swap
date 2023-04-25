/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:09 by chustei           #+#    #+#             */
/*   Updated: 2023/04/25 10:42:58 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_zero(char *nums)
{
	int	i;

/* 	if (nums[0] == '\0')
		return (1);

	if (nums[0] == '0' && ft_strlen(nums) > 1)
		return (1);
 */
	i = 0;
	while (nums[i])
	{
		if (nums[i] != '0')
			return (0);
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

