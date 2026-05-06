/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:03:17 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:43:05 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_tester(format[i + 1], &args, fd);
			i += 2;
		}
		else
		{
			if (format[i] == '\n')
				count += ft_putchar('\n', fd);
			else
				count += ft_putchar(format[i], fd);
			i++;
		}
	}
	va_end(args);
	return (count);
}
