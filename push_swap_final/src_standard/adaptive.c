/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:02:05 by vrahariv          #+#    #+#             */
/*   Updated: 2026/04/22 23:05:27 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_stack **stack_a, t_stack **stack_b, t_algo *algo)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (algo->disorder < 0.2)
	{
		simple(stack_a, stack_b, algo);
		algo->name = "O(n^2)";
	}
	else if (0.2 <= algo->disorder && algo->disorder < 0.5)
	{
		medium(stack_a, stack_b, algo);
		algo->name = "O(n√n)";
	}
	else
	{
		ft_radix_sort(stack_a, stack_b, algo);
		algo->name = "O(nlog n)";
	}
}
