/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/23 22:24:38 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/inc/libft.h"

int	ft_atoi_for_each(char **args)
{
	int	i;
	int	*nums;

	i = 1;
	while (args[i])
		i++;
	nums = (int *)malloc(sizeof(int) * i);
	i = 1;
	while (args[i])
	{
		if (ft_atoi(args[i]) == 0)
			return (1);
/* 		ft_printf("%i ", ft_atoi(args[i])); */
		nums[i -1] = ft_atoi(args[i]);
		i++;
	}
	i = -1;
	while (nums[++i])
		ft_printf("%i ", nums[i]);
	free(nums);
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

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_check_numeric(av) == 1 || ft_atoi_for_each(av) == 1)
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}

/*
Uusefull Link
https://42-cursus.gitbook.io/guide/rank-02/so_long/building-the-thing
*/
