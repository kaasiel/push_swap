/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 10:10:35 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 11:49:49 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	int	size;
	int	idx;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		insert_sort(stack_a, stack_b, little_srch(*stack_a), op_num);
		size--;
	}
	if (size == 3)
		tri3(stack_a, op_num);
	else if (size == 2 && (*stack_a)->rank > (*stack_a)->next->rank)
		sa(stack_a, op_num);
	while (*stack_b)
	{
		idx = big_srch(*stack_b);
		insert_sort_rev(stack_a, stack_b, idx, op_num);
	}
}
