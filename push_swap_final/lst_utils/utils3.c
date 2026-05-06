/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:33:51 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:45:32 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	little_srch(t_stack *stack_a)
{
	t_stack	*temp;
	int		min;
	int		index;
	int		i;

	if (!stack_a)
		return (-1);
	temp = stack_a;
	min = stack_a->content;
	index = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}
