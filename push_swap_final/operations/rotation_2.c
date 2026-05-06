/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:17:56 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:46:09 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_ra(t_stack **stack_a)
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

void	rr(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	no_ra(stack_a);
	no_ra(stack_b);
	op_num->rr++;
	write(1, "rr\n", 3);
}

void	no_rra(t_stack **stack_a)
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

void	rrr(t_stack **stack_a, t_stack **stack_b, t_algo *op_num)
{
	no_rra(stack_a);
	no_rra(stack_b);
	op_num->rrr++;
	write(1, "rrr\n", 4);
}
