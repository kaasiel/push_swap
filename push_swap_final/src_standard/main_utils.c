/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:32:03 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/01 11:01:31 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	strategy_selection(t_algo *algo, t_stack **stack_a,
		t_stack **stack_b)
{
	if (algo->simple)
		simple(stack_a, stack_b, algo);
	else if (algo->medium)
		medium(stack_a, stack_b, algo);
	else if (algo->complex)
		ft_radix_sort(stack_a, stack_b, algo);
	else if (algo->adaptive)
		ft_adaptive_sort(stack_a, stack_b, algo);
	else
		ft_adaptive_sort(stack_a, stack_b, algo);
	if (algo->benchmark)
		ft_benchmark(algo, *stack_a);
}

void	initializator(t_algo **algo)
{
	*algo = malloc(sizeof(t_algo));
	if (!*algo)
	{
		free(*algo);
		return ;
	}
	init_algo_flags(*algo);
}

void	init_algo_flags(t_algo *algo)
{
	algo->simple = 0;
	algo->medium = 0;
	algo->complex = 0;
	algo->benchmark = 0;
	algo->adaptive = 0;
	algo->name = "O(n√n)";
	algo->ra = 0;
	algo->rb = 0;
	algo->rra = 0;
	algo->rrb = 0;
	algo->rr = 0;
	algo->rrr = 0;
	algo->sa = 0;
	algo->sb = 0;
	algo->ss = 0;
	algo->pa = 0;
	algo->pb = 0;
	algo->total = 0;
	algo->disorder = 0.0f;
}
