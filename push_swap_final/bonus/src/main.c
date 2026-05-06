/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:26:34 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/05 10:14:52 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_algo_flags(t_algo *algo)
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

static int	init_and_parse(int argc, char **argv, t_stack **stack_a)
{
	t_algo	algo;

	init_algo_flags(&algo);
	if (!ft_parse_args(argc, argv, stack_a, &algo))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (0);
	}
	return (1);
}

static int	is_sorted_value(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	run_push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruction;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_and_parse(argc, argv, &stack_a))
		return (1);
	instruction = get_next_line(0);
	while (instruction)
	{
		trim_newline(instruction);
		if (!ft_execute_instructions(&stack_a, &stack_b, instruction))
			instruction_error(&stack_a, &stack_b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted_value(stack_a) && !stack_b)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (run_push_swap(argc, argv));
}
