/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:20:24 by vrahariv          #+#    #+#             */
/*   Updated: 2026/05/05 09:45:59 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				rank;
	struct s_list	*next;
}					t_stack;

typedef struct s_list2
{
	int				simple;
	int				medium;
	int				complex;
	int				benchmark;
	int				adaptive;
	char			*name;
	float			disorder;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				total;
}					t_algo;

void				pa(t_stack **pstack_b, t_stack **pstack_a);
void				pb(t_stack **pstack_a, t_stack **pstack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
void				free_stack(t_stack **stack);
void				trim_newline(char *instructions);
int					ft_execute_instructions(t_stack **stack_a,
						t_stack **stack_b, char *instructions);
void				instruction_error(t_stack **stack_a, t_stack **stack_b,
						char *instruction);
int					ft_parse_args(int argc, char **argv, t_stack **stack_a,
						t_algo *algo);
int					ft_is_sorted(t_stack *stack_a);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_check_range(long value, int sign, int *error);
long				ft_atol(char *str, int *error);
int					ft_check_duplicate(t_stack *stack, int value);
int					ft_only_whitespace(char *str);
int					ft_parse_one_number(char *str, int *i, t_stack **stack_a);
int					ft_parse_str_args(char *str, t_stack **stack_a);
#endif