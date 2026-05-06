/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrahariv <vrahariv@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:43:21 by belaindr          #+#    #+#             */
/*   Updated: 2026/05/05 10:47:47 by vrahariv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

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

void				pa(t_stack **pstack_b, t_stack **pstack_a, t_algo *algo);
void				pb(t_stack **pstack_a, t_stack **pstack_b, t_algo *algo);
void				sa(t_stack **stack_a, t_algo *algo);
void				three_two(t_stack **stack_a, t_stack **stack_b,
						t_algo *op_num);
void				sb(t_stack **stack_b, t_algo *algo);
void				ss(t_stack **stack_a, t_stack **stack_b, t_algo *algo);
void				ra(t_stack **stack_a, t_algo *algo);
void				rb(t_stack **stack_b, t_algo *algo);
void				rr(t_stack **stack_a, t_stack **stack_b, t_algo *algo);
void				rra(t_stack **stack_a, t_algo *algo);
void				rrb(t_stack **stack_b, t_algo *algo);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_algo *algo);

int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_check_range(long value, int sign, int *error);
long				ft_atol(char *str, int *error);
int					ft_check_duplicate(t_stack *stack, int value);
int					ft_only_whitespace(char *str);
int					ft_parse_one_number(char *str, int *i, t_stack **stack_a);
int					ft_parse_str_args(char *str, t_stack **stack_a);
int					ft_parse_args(int argc, char **argv, t_stack **stack_a,
						t_algo *algo);
t_stack				*ft_lstnew(int content);
void				ft_lstadd_front(t_stack **lst, t_stack *New);
int					ft_lstsize(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *New);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstclear(t_stack **lst, void (*del)(void *));
void				ft_lstdelone(t_stack *lst, void (*del)(void *));
int					smaller_chr(t_stack *stack_a, int ref);
int					big_srch(t_stack *stack_b);
int					little_srch(t_stack *stack_a);
void				insert_sort(t_stack **stack_a, t_stack **stack_b, int index,
						t_algo *algo);
void				insert_sort_rev(t_stack **stack_a, t_stack **stack_b,
						int index, t_algo *algo);
void				empty_stack_b(t_stack **stack_a, t_stack **stack_b,
						t_algo *algo);
void				tri3(t_stack **stack_a, t_algo *algo);
void				medium(t_stack **stack_a, t_stack **stack_b, t_algo *algo);
void				assign_ranks(t_stack *stack_a);
void				simple(t_stack **stack_a, t_stack **stack_b, t_algo *algo);
void				ft_radix_sort(t_stack **stack_a, t_stack **stack_b,
						t_algo *algo);
void				ft_adaptive_sort(t_stack **stack_a, t_stack **stack_b,
						t_algo *algo);
void				ft_count(t_algo *algo);
int					ft_is_sorted(t_stack *a);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_is_sorted(t_stack *stack_a);
int					ft_only_whitespace(char *str);
float				compute_disorder(t_stack *stack_a);
int					error_handling(int size, t_stack **stack_a);
int					algo_identifier(int argc, char **argv, t_algo *algo);
void				strategy_selection(t_algo *algo, t_stack **stack_a,
						t_stack **stack_b);
void				initializator(t_algo **algo);
void				free_stack(t_stack **stack);
void				ft_benchmark(t_algo *algo, t_stack *stack_a);
void				initializator(t_algo **algo);
void				init_algo_flags(t_algo *algo);
#endif
