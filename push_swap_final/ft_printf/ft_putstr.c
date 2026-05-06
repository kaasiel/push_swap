/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:29:52 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:36:05 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
