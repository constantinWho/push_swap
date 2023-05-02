/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/05/02 16:54:06 by chustei          ###   ########.fr       */
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

void	ft_store_stack_a(char **av, t_stack *stack)
{
	int	i;

	i = 0;
	while (av[++i])
		stack->a[i - 1] = ft_atoi(av[i]);
}

int	ft_min_pos(int *stack_a, int size)
{
	int	i;
	int	pos;
	int	min;

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

void	ft_rotate(int *stack, int pos, int size, char *move)
{
	int		*new_stack;
	int		i;
	int		rest;

	i = 0;
	rest = 0;
	new_stack = (int *)malloc(sizeof(int) * size);
	while (pos < size)
	{
		new_stack[i] = stack[pos];
		i++;
		pos++;
		if (ft_strncmp(move, "rra", 3) == 0)
			ft_printf("%s\n", move);
	}
	while (i < size)
	{
		new_stack[i] = stack[rest];
		i++;
		rest++;
		if (ft_strncmp(move, "ra", 2) == 0)
			ft_printf("%s\n", move);
	}
	i = 0;
	while (i < size)
	{
		stack[i] = new_stack[i];
		i++;
	}
	free(new_stack);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	ft_printf("sa\n");
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

void	ft_push_b(t_stack *stack)
{
	int	i;

	i = stack->size_b;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = stack->a[0];
	i = 0;
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}

void	ft_push_a(t_stack *stack)
{
	int	i;

	i = stack->size_a;
	while (--i >= 0)
		stack->a[i + 1] = stack->a[i];
	stack->a[0] = stack->b[0];
	i = 0;
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->size_a++;
	stack->size_b--;
	ft_printf("pa\n");
}

void ft_sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] < stack->a[2])
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_rotate(stack->a, 2, stack->size_a, "rra");
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 1, stack->size_a, "ra");
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] < stack->a[2])
	{
		ft_rotate(stack->a, 0, stack->size_a, "rra");
		ft_swap(&stack->a[0], &stack->a[1]);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 2, stack->size_a, "rra");
}

void	ft_push_swap(t_stack *stack)
{
	int	min_pos;

	if (stack->size_a == 3)
		ft_sort_three(stack);
	else if (stack->size_a > 3)
	{
		min_pos = ft_min_pos(stack->a, stack->size_a);
		if (stack->size_a - min_pos > stack->size_a / 2)
			ft_rotate(stack->a, min_pos, stack->size_a, "ra");
		else
			ft_rotate(stack->a, min_pos, stack->size_a, "rra");
		if (ft_check_sorted(stack->a, stack->size_a) == 1)
			ft_push_b(stack);
		if (ft_check_sorted(stack->a, stack->size_a) == 1)
			ft_push_swap(stack);
		ft_push_a(stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (ac > 1)
	{
		if (ft_check_numeric(av) == 1 || ft_check_atoi(av) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		stack->size_a = ft_get_size(av);
		stack->size_b = 0;
		stack->a = (int *)malloc(sizeof(int) * stack->size_a);
		stack->b = (int *)malloc(sizeof(int) * stack->size_a);
		ft_store_stack_a(av, stack);
		if (ft_check_double(stack) == 1)
			return (1);
		ft_check_output(stack);
		ft_push_swap(stack);
		ft_check_output(stack);
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
