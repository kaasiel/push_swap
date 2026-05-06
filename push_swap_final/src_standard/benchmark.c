/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:24:57 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:46:51 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_name(t_algo *algo, char **algo_name)
{
	if (algo->simple)
	{
		*algo_name = "Simple";
		algo->name = "O(n^2)";
	}
	else if (algo->medium)
	{
		*algo_name = "Medium";
		algo->name = "O(n√n)";
	}
	else if (algo->complex)
	{
		*algo_name = "Complex";
		algo->name = "O(nlog n)";
	}
	else
	{
		*algo_name = "Adaptive";
	}
}

void	ft_benchmark(t_algo *algo, t_stack *stack_a)
{
	float	disorder;
	char	*algo_name;

	algo->total = algo->ra + algo->rb + algo->rra + algo->rrb + algo->rr
		+ algo->rrr + algo->sa + algo->sb + algo->ss + algo->pa + algo->pb;
	(void)stack_a;
	disorder = algo->disorder * 100;
	strategy_name(algo, &algo_name);
	ft_printf(2, "[bench] disorder: %f%%\n", disorder);
	ft_printf(2, "[bench] strategy: %s / %s\n", algo_name, algo->name);
	ft_printf(2, "[bench] total_ops: %d\n", algo->total);
	ft_printf(2, "[bench] sa: %d sb : %d, ss : %d, pa : %d, pb : %d\n",
		algo->sa, algo->sb, algo->ss, algo->pa, algo->pb);
	ft_printf(2, "[bench] ra: %d rb : %d, rra : %d, rrb : %d, rr : %d, "
		"rrr :%d\n", algo->ra, algo->rb, algo->rra,
		algo->rrb, algo->rr, algo->rrr);
}
