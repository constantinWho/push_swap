/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/26 16:35:43 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left < right)
	{
		pivot = arr[right]; // choose last element as pivot
		i = left;
		j = right;
		while (i < j)
		{
			while (arr[i] < pivot)
				i++; // find element greater than pivot
			while (arr[j] > pivot)
				j--; // find element smaller than pivot
			if (i <= j)
			{
				swap(&arr[i], &arr[j]); // swap elements
				if (arr[0] > arr[1])
					ft_printf("sa\n");
				i++;
				j--;
			}
		}
		quicksort(arr, left, j); // recursively sort left sub-array
		quicksort(arr, i, right); // recursively sort right sub-array
	}
}

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

void	ft_push_swap(int *nums, int size)
{
	if (size == 2)
	{
		if (nums[0] > nums[1])
			return ;
		else
			ft_printf("sa\n");
	}
	if (size == 3)
	{
		
	}
	free(nums);
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
