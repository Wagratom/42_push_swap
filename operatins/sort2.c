/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:06:26 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:06:28 by wwallas-         ###   ########.fr       */
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
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		tmp->next->next = NULL;
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
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		(*stack_b)->next->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
