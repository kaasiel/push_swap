/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 02:55:04 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:35:26 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int fd)
{
	long	nbr;
	int		count;
	char	*ref;

	ref = "0123456789abcdef";
	nbr = n;
	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, fd);
	count += ft_putchar(ref[nbr % 16], fd);
	return (count);
}
