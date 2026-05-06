/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belaindr <belaindr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:32:41 by belaindr          #+#    #+#             */
/*   Updated: 2026/04/22 22:32:56 by belaindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*res;

	if (!(*list == NULL) && new)
	{
		res = ft_lstlast(*list);
		res->next = new;
	}
	else
		*list = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
