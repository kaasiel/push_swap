/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:08:05 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/11 14:36:47 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *s, int fd);
int	ft_putnbr(int n, int fd);
int	ft_puthex(unsigned int n, int fd);
int	ft_puthex_maj(unsigned int n, int fd);
int	ft_putendl(char c, int fd);
int	ft_bigint(unsigned int n, int fd);
int	ft_putfloat(double n, int fd);
int	ft_tester(char type, va_list *args, int fd);
int	ft_ptr(void *n, int fd);
#endif
