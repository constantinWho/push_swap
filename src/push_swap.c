/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:53 by chustei           #+#    #+#             */
/*   Updated: 2023/05/08 15:00:41 by chustei          ###   ########.fr       */
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

void	ft_push_sort(t_stack *stack, int pivot)
{
	int	i;

	i = -1;
	ft_printf("pivot: %d stack_b size: %d\n", pivot, stack->size_b);
/* 	while (++i < stack->size_b)
	{
		ft_push_a(stack);
		if (stack->a[i] > pivot)
			ft_rotate(stack->a, i, stack->size_a, "ra");
	} */
}

/* void	ft_push_swap(t_stack *stack)
{
	int	pivot;
	int	i;
	int	j;

	j = stack->size_a;
	i = -1;
	pivot = stack->a[stack->size_a - 1];
	while (++i < j - 1)
	{
		ft_printf("pivot: %d stack_a[%d]: %d\n", pivot, 0, stack->a[0]);
		if (stack->a[0] < pivot)
			ft_push_b(stack);
		else
			ft_rotate(stack->a, i, stack->size_a, "ra");
	}
	if (ft_check_sorted(stack->a, stack->size_a) == 1)
		ft_push_swap(stack);
}*/

void	ft_push_swap(t_stack *stack)
{
	int	min_pos;

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
}


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
