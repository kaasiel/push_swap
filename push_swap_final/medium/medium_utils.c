/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:30:56 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:31:17 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_chr(t_stack *stack_a, int ref)
{
	t_stack	*temp;
	int		min_rank;
	int		found;

	if (!stack_a)
		return (-1);
	found = 0;
	min_rank = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->rank < ref)
		{
			if (!found || temp->rank < min_rank)
			{
				min_rank = temp->rank;
				found = 1;
			}
		}
		temp = temp->next;
	}
	if (found)
		return (min_rank);
	return (-1);
}

int	big_srch(t_stack *stack_b)
{
	t_stack	*temp;
	int		max_rank;
	int		index;
	int		i;

	if (!stack_b)
		return (-1);
	temp = stack_b;
	max_rank = stack_b->rank;
	index = 0;
	i = 0;
	while (temp)
	{
		if (temp->rank > max_rank)
		{
			max_rank = temp->rank;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}
