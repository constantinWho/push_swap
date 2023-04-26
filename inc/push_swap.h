/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:52:26 by chustei           #+#    #+#             */
/*   Updated: 2023/04/26 14:12:11 by chustei          ###   ########.fr       */
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
void	quicksort(int *arr, int left, int right);

#endif
