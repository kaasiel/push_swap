/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:37:35 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 23:06:22 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(const char *arg, t_algo *algo);

int	ft_parse_args(int argc, char **argv, t_stack **stack_a, t_algo *algo)
{
	int	i;
	int	parsed_any;
	int	flag_status;

	parsed_any = 0;
	if (!algo_identifier(argc, argv, algo))
		return (0);
	i = 1;
	while (i < argc)
	{
		flag_status = handle_flag(argv[i], algo);
		if (flag_status == -1)
			return (0);
		if (flag_status == 1)
		{
			i++;
			continue ;
		}
		if (!ft_parse_str_args(argv[i], stack_a))
			return (0);
		parsed_any = 1;
		i++;
	}
	return (parsed_any);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	handle_flag(const char *arg, t_algo *algo)
{
	if (arg[0] == '-' && arg[1] == '-')
	{
		if (ft_strncmp(arg, "--simple", 10) == 0)
			algo->simple = 1;
		else if (ft_strncmp(arg, "--medium", 10) == 0)
			algo->medium = 1;
		else if (ft_strncmp(arg, "--complex", 10) == 0)
			algo->complex = 1;
		else if (ft_strncmp(arg, "--bench", 8) == 0)
			algo->benchmark = 1;
		else if (ft_strncmp(arg, "--adaptive", 11) == 0)
			algo->adaptive = 1;
		else
			return (-1);
		return (1);
	}
	return (0);
}

int	algo_identifier(int argc, char **argv, t_algo *algo)
{
	int	i;
	int	flag_status;

	i = 1;
	while (i < argc)
	{
		flag_status = handle_flag(argv[i], algo);
		if (flag_status == -1)
			return (0);
		i++;
	}
	return (1);
}
