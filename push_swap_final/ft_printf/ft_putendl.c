/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 05:55:58 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:32:05 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putendl(char c, int fd)
{
	int	count;

	count = 0;
	count += ft_putchar(c, fd);
	count += ft_putchar('\n', fd);
	return (count);
}
