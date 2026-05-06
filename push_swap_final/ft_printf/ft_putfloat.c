/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:10:00 by belaindr         #+#    #+#             */
/*   Updated: 2026/04/11 11:10:00 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

static double	ft_round(double value)
{
	double	rounding;
	int		i;

	rounding = 0.5;
	i = 0;
	while (i < 2)
	{
		rounding /= 10.0;
		i++;
	}
	return (value + rounding);
}

static int	ft_putull(unsigned long long n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putull(n / 10, fd);
	count += ft_putchar((n % 10) + '0', fd);
	return (count);
}

static int	ft_putfrac(double frac, int fd)
{
	int	count;
	int	i;
	int	digit;

	count = 0;
	i = 0;
	while (i < 2)
	{
		frac *= 10.0;
		digit = (int)frac;
		count += ft_putchar(digit + '0', fd);
		frac -= digit;
		i++;
	}
	return (count);
}

int	ft_putfloat(double n, int fd)
{
	int					count;
	double				value;
	unsigned long long	int_part;
	double				frac;

	count = 0;
	value = n;
	if (value != value)
		return (ft_putstr("nan", fd));
	if (value > DBL_MAX)
		return (ft_putstr("inf", fd));
	if (value < -DBL_MAX)
		return (ft_putstr("-inf", fd));
	if (value < 0.0)
	{
		count += ft_putchar('-', fd);
		value = -value;
	}
	value = ft_round(value);
	int_part = (unsigned long long)value;
	count += ft_putull(int_part, fd);
	count += ft_putchar('.', fd);
	frac = value - (double)int_part;
	count += ft_putfrac(frac, fd);
	return (count);
}
