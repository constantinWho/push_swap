/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/04/28 23:53:33 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_get_size(char **av)
{
	int size;

	size = 1;
	while (av[size])
		size++;
	return (size - 1);
}

int *ft_store_stack_a(char **av, int size)
{
	int i;
	int *stack_a;

	stack_a = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (av[++i])
		stack_a[i - 1] = ft_atoi(av[i]);
	return (stack_a);
}

int ft_min_pos(int *stack_a, int size)
{
	int i;
	int pos;
	int min;

	pos = 0;
	min = stack_a[0];
	i = 0;
	while (++i < size)
	{
		if (stack_a[i] < min)
		{
			min = stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

void ft_ra(int *stack, int pos, int size)
{
	int *new_stack;
	int i;
	int rest;

	i = 0;
	rest = 0;
	new_stack = (int *)malloc(sizeof(int) * size);
	while (pos < size)
	{
		new_stack[i] = stack[pos];
		i++;
		pos++;
	}
	while (i < size)
	{
		new_stack[i] = stack[rest];
		i++;
		rest++;
		ft_printf("ra\n");
	}
	i = 0;
	while (i < size)
	{
		stack[i] = new_stack[i];
		i++;
	}
	free(new_stack);
}

void ft_rra(int *stack, int pos, int size)
{
	int *new_stack;
	int i;
	int rest;

	i = 0;
	rest = 0;
	new_stack = (int *)malloc(sizeof(int) * size);
	while (pos < size)
	{
		new_stack[i] = stack[pos];
		i++;
		pos++;
	}
	while (i < size)
	{
		new_stack[i] = stack[rest];
		i++;
		rest++;
		ft_printf("rra\n");
	}
	i = 0;
	while (i < size)
	{
		stack[i] = new_stack[i];
		i++;
	}
	free(new_stack);
}

int ft_check_sorted(int *stack_a, int size)
{
	int i;
	int curr;

	i = 0;
	while (++i < size)
	{
		curr = stack_a[i - 1];
		if (curr > stack_a[i])
			return (1);
	}
	return (0);
}

void ft_push_swap(int *stack_a, int size)
{
	// int *stack_b;
	int min_pos;

	// stack_b = (int *)malloc(sizeof(int) * size);
	if (size > 1)
	{
		min_pos = ft_min_pos(stack_a, size);
		if (size - min_pos > size / 2)
			ft_ra(stack_a, min_pos, size);
		else
			ft_rra(stack_a, min_pos, size);
		if (ft_check_sorted(stack_a, size) == 1)
			ft_printf("pb\n");
	}
}

int main(int ac, char **av)
{
	int *stack_a;
	int size;

	if (ac > 1)
	{
		if (ft_check_numeric(av) == 1 || ft_check_atoi(av) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		size = ft_get_size(av);
		stack_a = ft_store_stack_a(av, size);
		if (ft_check_double(stack_a, size) == 1)
			return (1);
		ft_check_output(stack_a, size);
		ft_push_swap(stack_a, size);
		ft_check_output(stack_a, size);
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
