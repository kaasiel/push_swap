/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:18:21 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/06 14:22:31 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	trim_newline(char *instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (instructions[i] == '\n')
		{
			instructions[i] = '\0';
			break ;
		}
		i++;
	}
}

int	ft_execute_instructions(t_stack **stack_a, t_stack **stack_b,
						char *instructions)
{
	if (ft_strncmp(instructions, "sa", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(instructions, "sb", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(instructions, "ss", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(instructions, "pa", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(instructions, "pb", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(instructions, "ra", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(instructions, "rb", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(instructions, "rr", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(instructions, "rra", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(instructions, "rrb", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(instructions, "rrr", 4) == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	instruction_error(t_stack **stack_a, t_stack **stack_b,
					char *instruction)
{
	write(2, "Error\n", 6);
	free(instruction);
	free_stack(stack_b);
	free_stack(stack_a);
	exit(1);
}

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
