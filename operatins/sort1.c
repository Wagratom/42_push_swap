/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:06:19 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:06:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_stack **stack_a)
{
	t_stack	tmp;

	if ((*stack_a)->next)
	{
		tmp.content = (*stack_a)->next->content;
		(*stack_a)->next->content = (*stack_a)->content;
		(*stack_a)->content = tmp.content;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	tmp;

	if ((*stack_b)->next)
	{
		tmp.content = (*stack_b)->next->content;
		(*stack_b)->next->content = (*stack_b)->content;
		(*stack_b)->content = tmp.content;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		if (*stack_b)
			(*stack_b)->prev = NULL;
		if (!*stack_a)
			(*stack_a) = (*stack_b);
		else
		{
			(*stack_a)->prev = tmp;
			tmp->next = (*stack_a);
			(*stack_a) = tmp;
		}
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		(*stack_a) = (*stack_a)->next;
		tmp->next = NULL;
		if (*stack_a)
			(*stack_a)->prev = NULL;
		if (!*stack_b)
			(*stack_b) = tmp;
		else
		{
			(*stack_b)->prev = tmp;
			tmp->next = (*stack_b);
			(*stack_b) = tmp;
		}
	}
	write(1, "pb\n", 3);
}
