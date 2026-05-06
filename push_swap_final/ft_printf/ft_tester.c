/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 04:13:33 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:36:36 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tester(char type, va_list *args, int fd)
{
	if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(*args, int), fd));
	else if (type == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), fd));
	else if (type == 'X')
		return (ft_puthex_maj(va_arg(*args, unsigned int), fd));
	else if (type == 's')
		return (ft_putstr(va_arg(*args, char *), fd));
	else if (type == 'c')
		return (ft_putchar((char)va_arg(*args, int), fd));
	else if (type == 'u')
		return (ft_bigint(va_arg(*args, unsigned int), fd));
	else if (type == 'f')
		return (ft_putfloat(va_arg(*args, double), fd));
	else if (type == '%')
		return (ft_putchar('%', fd));
	else if (type == 'p')
		return (ft_ptr(va_arg(*args, void *), fd));
	return (0);
}
