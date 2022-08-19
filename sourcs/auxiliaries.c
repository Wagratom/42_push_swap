/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:02:51 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/19 11:53:27 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	my_error(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	valid_stack(t_stack *stack)
{	
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
