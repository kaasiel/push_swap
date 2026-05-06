/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:34:34 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:34:42 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri3(t_stack **stack_a, t_algo *op_num)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->rank;
	second = (*stack_a)->next->rank;
	third = (*stack_a)->next->next->rank;
	if (first > second && second < third && first < third)
		sa(stack_a, op_num);
	else if (first > second && second > third)
	{
		sa(stack_a, op_num);
		rra(stack_a, op_num);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, op_num);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, op_num);
		ra(stack_a, op_num);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, op_num);
}

void	insert_sort(t_stack **stack_a, t_stack **stack_b,
			int index, t_algo *algo)
{
	int	size;
	int	steps;

	size = ft_lstsize(*stack_a);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack_a, algo);
			index--;
		}
	}
	else
	{
		steps = size - index;
		while (steps > 0)
		{
			rra(stack_a, algo);
			steps--;
		}
	}
	pb(stack_a, stack_b, algo);
}

void	insert_sort_rev(t_stack **stack_a, t_stack **stack_b,
			int index, t_algo *algo)
{
	int	steps;
	int	size;

	size = ft_lstsize(*stack_b);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			rb(stack_b, algo);
			index--;
		}
	}
	else
	{
		steps = size - index;
		while (steps > 0)
		{
			rrb(stack_b, algo);
			steps--;
		}
	}
	pa(stack_a, stack_b, algo);
}

void	empty_stack_b(t_stack **stack_a, t_stack **stack_b, t_algo *algo)
{
	int	index;
	int	size_b;

	size_b = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		index = big_srch(*stack_b);
		insert_sort_rev(stack_a, stack_b, index, algo);
	}
}
