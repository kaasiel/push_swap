/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:19:17 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:28:21 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **pstack_a, t_stack **pstack_b, t_algo *op_num)
{
	t_stack	*temp;

	if (!pstack_b || !*pstack_b)
		return ;
	temp = *pstack_b;
	*pstack_b = (*pstack_b)->next;
	ft_lstadd_front(pstack_a, temp);
	op_num->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **pstack_a, t_stack **pstack_b, t_algo *op_num)
{
	t_stack	*temp;

	if (!pstack_a || !*pstack_a)
		return ;
	temp = *pstack_a;
	*pstack_a = (*pstack_a)->next;
	ft_lstadd_front(pstack_b, temp);
	op_num->pb++;
	write(1, "pb\n", 3);
}
