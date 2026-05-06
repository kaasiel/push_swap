/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:57:47 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/05 10:41:03 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*node2;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	node2 = temp->next;
	if (node2)
	{
		temp->next = node2->next;
		node2->next = temp;
		*stack_a = node2;
	}
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*node2;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	node2 = temp->next;
	if (node2)
	{
		temp->next = node2->next;
		node2->next = temp;
		*stack_b = node2;
	}
}

void	no_sa(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*node2;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	node2 = temp->next;
	if (node2)
	{
		temp->next = node2->next;
		node2->next = temp;
		*stack_a = node2;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	no_sa(stack_a);
	no_sa(stack_b);
}
