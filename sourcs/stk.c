/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:07:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:07:02 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_stknew(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->content = content;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*ft_stklast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		tmp = ft_stklast(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
}
