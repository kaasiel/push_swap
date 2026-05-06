/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 08:22:40 by belaindr          #+#    #+#             */
/*   Updated: 2026/02/14 09:38:34 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(void *n, int fd)
{
	char	*ref;
	int		count;

	ref = "0123456789abcdef";
	count = 0;
	if (!n)
		return (ft_putstr("(nil)", fd));
	if ((unsigned long)n >= 16)
		count += ft_adress((void *)((unsigned long)n / 16), fd);
	count += ft_putchar(ref[(unsigned long)n % 16], fd);
	return (count);
}

int	ft_ptr(void *n, int fd)
{
	int	count;

	if (!n)
		return (ft_putstr("(nil)", fd));
	count = 0;
	count += ft_putstr("0x", fd);
	count += ft_adress(n, fd);
	return (count);
}
