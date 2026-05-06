/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:06:34 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/01 10:57:11 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, t_algo *op_num)
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
		write(1, "sa\n", 3);
	}
	op_num->sa++;
}

void	sb(t_stack **stack_b, t_algo *op_num)
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
		write(1, "sb\n", 3);
	}
	op_num->sb++;
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

void	ss(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	no_sa(stack_a);
	no_sa(stack_b);
	op_num->ss++;
	write(1, "ss\n", 3);
}
