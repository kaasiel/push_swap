/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 03:42:08 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:35:08 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_maj(unsigned int n, int fd)
{
	long	nbr;
	int		count;
	char	*ref;

	ref = "0123456789ABCDEF";
	nbr = n;
	count = 0;
	if (nbr >= 16)
		count += ft_puthex_maj(nbr / 16, fd);
	count += ft_putchar(ref[nbr % 16], fd);
	return (count);
}
