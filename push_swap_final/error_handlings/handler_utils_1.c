/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:35:36 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:36:36 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_check_range(long value, int sign, int *error)
{
	if ((sign == 1 && value > 2147483647) || (sign == -1
			&& value > 2147483648L))
	{
		*error = 1;
		return (0);
	}
	return (1);
}

long	ft_atol(char *str, int *error)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	value = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		if (!ft_check_range(value, sign, error))
			return (0);
		i++;
	}
	return (value * sign);
}
