/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:59:14 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/05 10:40:44 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **pstack_a, t_stack **pstack_b)
{
	t_stack	*temp;

	if (!pstack_b || !*pstack_b)
		return ;
	temp = *pstack_b;
	*pstack_b = (*pstack_b)->next;
	ft_lstadd_front(pstack_a, temp);
}

void	pb(t_stack **pstack_a, t_stack **pstack_b)
{
	t_stack	*temp;

	if (!pstack_a || !*pstack_a)
		return ;
	temp = *pstack_a;
	*pstack_a = (*pstack_a)->next;
	ft_lstadd_front(pstack_b, temp);
}
