/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/19 18:30:57 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/inc/libft.h"

void	ft_perror(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
}

int	ft_check_zero(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_for_each(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if ((ft_atoi(args[i]) == 0 && ft_check_zero(args[i]) != 0))
		{
			ft_perror("Provide Only Numeric Arguments");
			return (1);
		}
		ft_printf("%i ", ft_atoi(args[i]));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!(ft_strchr(av[1], ' ')))
			ft_atoi_for_each(av);
		ft_atoi_for_each(ft_split(av[1], ' '));
	}
	else if (ac > 2)
		ft_atoi_for_each(av);
	else
		ft_perror("No Argumets Provided");
	return (0);
}

/* 
Uusefull Link
https://42-cursus.gitbook.io/guide/rank-02/so_long/building-the-thing 
*/