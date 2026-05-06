/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:39:19 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:39:33 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	t_stack		*current;
	t_stack		*check;
	long long	mistakes;
	long long	total_pairs;
	int			size;

	mistakes = 0;
	size = ft_lstsize(stack_a);
	if (size < 2)
		return (0.0);
	total_pairs = (long long)size * (size - 1) / 2;
	current = stack_a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->rank > check->rank)
				mistakes++;
			check = check->next;
		}
		current = current->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
