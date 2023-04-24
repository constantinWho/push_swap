/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:25:09 by chustei           #+#    #+#             */
/*   Updated: 2023/04/24 15:29:46 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_numeric(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-' || args[i][j] == '+')
				j++;
			if (ft_isdigit(args[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double(int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (nums[j] == nums[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
