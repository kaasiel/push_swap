/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:31:34 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:31:43 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pre_sort_check(t_stack **stack_a, t_algo *algo)
{
	assign_ranks(*stack_a);
	algo->disorder = compute_disorder(*stack_a);
	if (!error_handling(ft_lstsize(*stack_a), stack_a))
	{
		if (algo->benchmark)
			ft_benchmark(algo, *stack_a);
		free_stack(stack_a);
		free(algo);
		return (0);
	}
	return (1);
}

static int	init_and_parse(int argc, char **argv, t_stack **stack_a,
			t_algo **algo)
{
	initializator(algo);
	if (!*algo)
		return (0);
	if (!ft_parse_args(argc, argv, stack_a, *algo))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		free(*algo);
		return (0);
	}
	return (1);
}

static int	run_push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_algo	*algo;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_and_parse(argc, argv, &stack_a, &algo))
		return (1);
	if (!pre_sort_check(&stack_a, algo))
		return (0);
	strategy_selection(algo, &stack_a, &stack_b);
	free_stack(&stack_b);
	free_stack(&stack_a);
	free(algo);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (run_push_swap(argc, argv));
}
