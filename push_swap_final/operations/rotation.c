/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:14:58 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:17:27 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, t_algo *op_num)
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
	op_num->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, t_algo *op_num)
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
	op_num->rrb++;
	write(1, "rrb\n", 4);
}

void	ra(t_stack **stack_a, t_algo *op_num)
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
	op_num->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, t_algo *op_num)
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
	op_num->rb++;
	write(1, "rb\n", 3);
}
