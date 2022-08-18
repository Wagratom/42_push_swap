/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:01:38 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/18 16:14:35 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if ((*stack_a)->next)
	{
		tmp = ft_stklast(*stack_a);
		tmp->next = *stack_a;
		(*stack_a)->prev = tmp;
		(*stack_a)->next = NULL;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_b)->next)
	{
		tmp = ft_stklast(*stack_b);
		tmp->next = *stack_b;
		(*stack_b)->prev = tmp;
		(*stack_b)->next = NULL;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
