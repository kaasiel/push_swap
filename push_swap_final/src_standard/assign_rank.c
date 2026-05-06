/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:29:08 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/08 14:26:14 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		r;

	current = stack_a;
	while (current)
	{
		r = 0;
		compare = stack_a;
		while (compare)
		{
			if (compare->content < current->content)
				r++;
			compare = compare->next;
		}
		current->rank = r;
		current = current->next;
	}
}
