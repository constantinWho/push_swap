/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:52:26 by chustei           #+#    #+#             */
/*   Updated: 2023/04/28 22:13:57 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../lib/libft/inc/libft.h"

int ft_check_numeric(char **args);
int ft_check_double(int *stack_a, int size);
int ft_check_zero(char *stack_a);
int ft_check_atoi(char **av);
void ft_check_output(int *stack_a, int size);

#endif
