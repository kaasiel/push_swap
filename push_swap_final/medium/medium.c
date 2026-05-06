/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:30:18 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:30:39 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_two(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 3)
		tri3(stack_a, op_num);
	if (ft_lstsize(*stack_a) == 2 && (*stack_a)->rank > (*stack_a)->next->rank)
		sa(stack_a, op_num);
	return ;
}

void	medium_main(int chunk, t_stack **a, t_stack **b,
		t_algo *op_num)
{
	int	low;
	int	high;
	int	pushed;
	int	size;

	low = 0;
	high = chunk;
	pushed = 0;
	size = ft_lstsize(*a);
	while (pushed < size)
	{
		if ((*a)->rank <= high)
		{
			pb(a, b, op_num);
			if ((*b)->rank <= low)
				rb(b, op_num);
			low++;
			high++;
			pushed++;
		}
		else
			ra(a, op_num);
	}
}

void	medium(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	int	chunk;
	int	idx;
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 6)
	{
		simple(stack_a, stack_b, op_num);
		return ;
	}
	if (size <= 100)
		chunk = 20;
	else
		chunk = 45;
	medium_main(chunk, stack_a, stack_b, op_num);
	three_two(stack_a, stack_b, op_num);
	while (*stack_b)
	{
		idx = big_srch(*stack_b);
		insert_sort_rev(stack_a, stack_b, idx, op_num);
	}
}
