/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 05:48:51 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:28:37 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bigint(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_bigint(n / 10, fd);
	count += ft_putchar((n % 10) + '0', fd);
	return (count);
}
