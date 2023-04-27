/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/27 16:12:45 by chustei          ###   ########.fr       */
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

int	*ft_store_nums(char **av, int size)
{
	int	i;
	int	*nums;

	nums = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (av[++i])
		nums[i - 1] = ft_atoi(av[i]);
	return (nums);
}



int	*ft_sort(int *nums, int size)
{
	int	*sorted;
	int	i;
	int	j;
	int	temp;

	sorted = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		sorted[i] = nums[i];
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	i = 0;
	while (i < size)
		ft_printf("%i ", sorted[i++]);
	ft_printf("\n");
	return (sorted);
}

void	ft_swap_a(int *nums)
{
	int	temp;

	temp = nums[0];
	nums[0] = nums[1];
	nums[1] = temp;
	ft_printf("sa\n");
}

void	ft_sort_three(int *nums)
{
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
	}
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		ft_printf("sa\n");
		ft_printf("rra\n");
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		ft_printf("sa\n");
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
		ft_printf("ra\n");
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
		ft_printf("rra\n");
}

void	ft_sort_four(int *nums, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = nums[0];
	pos = 0;
	while (++i < size)
	{
		if (nums[i] < min)
		{
			min = nums[i];
			pos = i;
		}
	}
	if (pos == 0)
		ft_printf("pb\n");
	else if (pos == 1)
		ft_printf("sb\npb\n");
	else if (pos == 2)
		ft_printf("rrb\npb\n");
	else if (pos == 3)
		ft_printf("rb\nsb\npb\n");
	ft_sort_three(nums);
	ft_printf("pa\n");
}

void	ft_sort_five(int *nums, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = nums[0];
	pos = 0;
	while (++i < size)
	{
		if (nums[i] < min)
		{
			min = nums[i];
			pos = i;
		}
	}
	if (pos == 0)
		ft_printf("pb\n");
	else if (pos == 1)
		ft_printf("sb\npb\n");
	else if (pos == 2)
		ft_printf("rrb\npb\n");
	else if (pos == 3)
		ft_printf("rb\nsb\npb\n");
	else if (pos == 4)
		ft_printf("rrb\nsb\npb\n");
	ft_sort_four(nums, size - 1);
	ft_printf("pa\n");
}

void	ft_sort_hundred(int *nums, int size)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = nums[0];
	pos = 0;
	while (++i < size)
	{
		if (nums[i] < min)
		{
			min = nums[i];
			pos = i;
		}
	}
	if (pos == 0)
		ft_printf("pb\n");
	else if (pos == 1)
		ft_printf("sb\npb\n");
	else if (pos == 2)
		ft_printf("rrb\npb\n");
	else if (pos == 3)
		ft_printf("rb\nsb\npb\n");
	else if (pos == 4)
		ft_printf("rrb\nsb\npb\n");
	if (size == 0)
		return ;
	ft_sort_hundred(nums, size - 1);
	ft_printf("pa\n");
}

void	ft_push_swap(int *nums, int size)
{
	int	*sorted;
	int	i;

	sorted = ft_sort(nums, size);
	i = 0;
	while (i < size)
	{
		if (nums[i] != sorted[i])
		{
			if (size == 2)
				ft_swap_a(nums);
			else if (size == 3)
				ft_sort_three(nums);
			else if (size == 4)
				ft_sort_four(nums, size);
			else if (size == 5)
				ft_sort_five(nums, size);
			else
				ft_sort_hundred(nums, size);
			break ;
		}
		i++;
	}
	free(sorted);
}

int	main(int ac, char **av)
{
	int	*nums;
	int	size;

	if (ac > 1)
	{
		if (ft_check_numeric(av) == 1 || ft_check_atoi(av) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		size = ft_get_size(av);
		nums = ft_store_nums(av, size);
		if (ft_check_double(nums, size) == 1)
			return (1);
		ft_check_output(nums, size);
		ft_push_swap(nums, size);
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

/*
Uusefull Link
https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing
*/
