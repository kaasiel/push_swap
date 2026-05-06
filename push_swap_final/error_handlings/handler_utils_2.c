/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:35:53 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:36:49 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->content == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_only_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_one_number(char *str, int *i, t_stack **stack_a)
{
	int		j;
	long	value;
	int		error;

	while (ft_isspace(str[*i]))
		(*i)++;
	if (!str[*i])
		return (0);
	j = *i;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] && !ft_isspace(str[*i]))
		return (0);
	error = 0;
	value = ft_atol(str + j, &error);
	if (error || ft_check_duplicate(*stack_a, (int)value))
		return (0);
	ft_lstadd_back(stack_a, ft_lstnew((int)value));
	return (1);
}

int	ft_parse_str_args(char *str, t_stack **stack_a)
{
	int	i;
	int	found;

	if (!str[0])
		return (0);
	i = 0;
	found = 0;
	while (str[i])
	{
		if (ft_only_whitespace(str + i))
			break ;
		if (!ft_parse_one_number(str, &i, stack_a))
			return (0);
		found = 1;
	}
	if (found == 0)
		return (0);
	return (1);
}
