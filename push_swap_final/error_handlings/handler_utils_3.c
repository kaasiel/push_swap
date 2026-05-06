/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:38:28 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:45:00 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->rank > stack_a->next->rank)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}

int	error_handling(int size, t_stack **stack_a)
{
	if (size <= 1)
		return (0);
	if (ft_is_sorted(*stack_a))
		return (0);
	return (1);
}
