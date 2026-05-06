/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:31:56 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:35:44 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	long	nbr;
	char	res;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10, fd);
	res = nbr % 10 + '0';
	count += ft_putchar(res, fd);
	return (count);
}
