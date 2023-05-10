/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:53 by chustei           #+#    #+#             */
/*   Updated: 2023/05/10 17:26:12 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	ft_printf("sa\n");
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] < stack->a[2])
		ft_swap(&stack->a[0], &stack->a[1]);
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_rotate(stack->a, 2, stack->size_a, "rra");
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && \
		stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 1, stack->size_a, "ra");
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
		stack->a[0] < stack->a[2])
	{
		ft_rotate(stack->a, 0, stack->size_a, "rra");
		ft_swap(&stack->a[0], &stack->a[1]);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && \
		stack->a[0] > stack->a[2])
		ft_rotate(stack->a, 2, stack->size_a, "rra");
}

void	ft_sort_five(t_stack *stack)
{
	int	i;
	int	j;
	int	min_pos;

	i = -1;
	j = stack->size_a;
	while (++i < j - 1)
	{
		min_pos = ft_min_pos(stack->a, stack->size_a);
		if (min_pos == 0)
			ft_push_b(stack);
		else if (min_pos == 1)
			ft_rotate(stack->a, 1, stack->size_a, "ra");
		else if (min_pos == 2)
			ft_rotate(stack->a, 2, stack->size_a, "ra");
		else if (min_pos == 3)
			ft_rotate(stack->a, 3, stack->size_a, "ra");
		else if (min_pos == 4)
			ft_rotate(stack->a, 4, stack->size_a, "ra");
	}
	ft_sort_three(stack);
	ft_push_a(stack);
	ft_push_a(stack);
}

void	ft_sort(t_stack *stack)
{
	int	max;
	int	i;
	int	j;
	int	ratio;

	max = stack->size_a - 1;
	ratio = 10;
	ft_printf("max: %d\n", max);
	i = -1;
	while (++i < max + 1)
	{
		j = -1;
		while (++j < max + 1)
		{
			if (stack->a[j] < ratio && stack->a[j] != max && \
			stack->a[j] != max - 1 && stack->a[j] != max - 2 && \
			stack->a[j] != max - 3 && stack->a[j] != max - 4)
			{
				if (j == 0)
				{
					ft_push_b(stack);
/* 					ft_rotate(stack->b, j, stack->size_b, "rb"); */
				}
				if (max - j > max / 2)
					ft_rotate(stack->a, j, stack->size_a, "ra");
				else
					ft_rotate(stack->a, j, stack->size_a, "rra");
				break ;
			}
		}
	}
/* 	ft_push_swap(stack);
	if (stack->size_b > 0)
		ft_push_a(stack); */
}

void	ft_push_swap(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->size_a == 2)
		ft_swap(&stack->a[0], &stack->a[1]);
/* 	ft_printf("size_a: %d\n", stack->size_a); */
	if (stack->size_a == 3)
		ft_sort_three(stack);
	if (stack->size_a == 5)
		ft_sort_five(stack);
	if (stack->size_a > 5)
		ft_sort(stack);
/* 	ft_printf("size_a: %d\n", stack->size_a); */
}

/*

void	ft_quick_sort(int *stack, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_partition(stack, low, high);
		ft_quick_sort(stack, low, pivot - 1);
		ft_quick_sort(stack, pivot + 1, high);
	}
} */

/* void	ft_push_swap(t_stack *stack)
{
	int	min_pos;

	if (stack->a[0] < stack->a[1])
		ft_swap(&stack->a[0], &stack->a[1]);
	if (stack->size_a == 3)
		ft_sort_three(stack);
	else if (stack->size_a > 1)
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
		if (stack->size_b > 0)
			ft_push_a(stack);
	}
} */

/* #include <stdio.h>

void	quicksort(int arr[], int len)
{
	int	pivot;
	int	left[len];
	int	right[len];
	int l_len = 0, r_len = 0;

	if (len <= 1)
		return ;
	pivot = arr[len / 2];

	for (int i = 0; i < len; i++)
	{
		if (arr[i] < pivot)
			left[l_len++] = arr[i];
		else if (arr[i] > pivot)
			right[r_len++] = arr[i];
	}

    quicksort(left, l_len);
    quicksort(right, r_len);

    int i = 0;
    for (int j = 0; j < l_len; j++) {
        arr[i++] = left[j];
    }
    arr[i++] = pivot;
    for (int j = 0; j < r_len; j++) {
        arr[i++] = right[j];
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int len = sizeof(arr) / sizeof(int);

    quicksort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
} */
