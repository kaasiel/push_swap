/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:59:58 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/05 10:40:52 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*node1;
	int		size;
	int		i;

	i = 1;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	size = ft_lstsize(*stack_a);
	node1 = *stack_a;
	while (i < size - 1)
	{
		node1 = node1->next;
		i++;
	}
	last->next = *stack_a;
	node1->next = NULL;
	*stack_a = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*node1;
	int		size;
	int		i;

	i = 1;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	size = ft_lstsize(*stack_b);
	node1 = *stack_b;
	while (i < size - 1)
	{
		node1 = node1->next;
		i++;
	}
	last->next = *stack_b;
	node1->next = NULL;
	*stack_b = last;
}

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)->next;
	last->next = temp;
	temp->next = NULL;
}
