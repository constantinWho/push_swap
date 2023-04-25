/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/25 10:46:42 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_store_nums(char **args)
{
	int	i;
	int	*nums;
	int	size;

	size = 1;
	while (args[size])
		size++;
	nums = (int *)malloc(sizeof(int) * (size - 1));
	i = 1;
	while (args[i])
	{
		if (ft_atoi(args[i]) == 0)
			if (ft_check_zero(args[i]) == 1)
				return (1);
		nums[i - 1] = ft_atoi(args[i]);
		i++;
	}
	i = 0;
	if (ft_check_double(nums, size - 1) == 1)
		return (1);
	while (i < size - 1)
		ft_printf("%i ", nums[i++]);
	free(nums);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_check_numeric(av) == 1 || ft_store_nums(av) == 1)
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
