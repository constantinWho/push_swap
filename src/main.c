/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:22:23 by chustei           #+#    #+#             */
/*   Updated: 2023/05/05 15:09:47 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_store_stack_a(char **av, t_stack *stack)
{
	int	i;

	i = 0;
	while (av[++i])
		stack->a[i - 1] = ft_atoi(av[i]);
}

void	ft_print_output(t_stack	*stack)
{
	int	i;

	i = 0;
	ft_printf("stack_a: ");
	while (i < stack->size_a)
		ft_printf("%i ", stack->a[i++]);
	i = 0;
	ft_printf("\n");
	ft_printf("stack_b: ");
	while (i < stack->size_b)
		ft_printf("%i ", stack->b[i++]);
	ft_printf("\n");
}

int	ft_execute(char **av, t_stack *stack)
{
	if (ft_check_numeric(av) == 1 || ft_check_atoi(av) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_init_stacks(av, stack);
	ft_store_stack_a(av, stack);
	if (ft_check_double(stack) == 1)
		return (1);
	ft_print_output(stack);
	ft_push_swap(stack);
	ft_print_output(stack);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (ac > 1)
	{
		if (ft_execute(av, stack) == 1)
		{
			ft_free_stacks(stack);
			return (1);
		}
		ft_free_stacks(stack);
	}
	else
	{
		free(stack);
		return (1);
	}
	return (0);
}
