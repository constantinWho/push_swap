/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:52:26 by chustei           #+#    #+#             */
/*   Updated: 2023/04/27 16:04:32 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../lib/libft/inc/libft.h"

int		ft_check_numeric(char **args);
int		ft_check_double(int *nums, int size);
int		ft_check_zero(char *nums);
int		ft_check_atoi(char **av);
void	ft_check_output(int *nums, int size);
void	ft_push_swap(int *nums, int size);
void	ft_sort_hundred(int *nums, int size);
void	ft_sort_five(int *nums, int size);
void	ft_sort_four(int *nums, int size);
void	ft_sort_three(int *nums);
void	ft_swap_a(int *nums);
int		*ft_sort(int *nums, int size);

#endif
