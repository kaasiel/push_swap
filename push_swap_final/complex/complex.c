/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:39:49 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:44:23 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_stack **stack_a, t_stack **stack_b,
			t_algo *algo, int bit)
{
	int		j;
	int		size;
	t_stack	*current;

	size = ft_lstsize(*stack_a);
	j = 0;
	while (j < size)
	{
		current = *stack_a;
		if (((current->rank >> bit) & 1) == 0)
			pb(stack_a, stack_b, algo);
		else
			ra(stack_a, algo);
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b, algo);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, t_algo *algo)
{
	int		size;
	int		max_bits;
	int		max_rank;
	int		i;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
	{
		simple(stack_a, stack_b, algo);
		return ;
	}
	if (size <= 3)
		three_two(stack_a, stack_b, algo);
	max_bits = 0;
	max_rank = size - 1;
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack_a, stack_b, algo, i);
		i++;
	}
}
