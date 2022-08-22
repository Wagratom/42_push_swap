/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:35:16 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 14:21:27 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack **stack, int size)
{
	if (size == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			sa(stack);
	}
	else
	{
		while (valid_stack(*stack))
		{
			if ((*stack)->content < (*stack)->next->content)
				rra(stack);
			if ((*stack)->content > (*stack)->next->content
				&& (*stack)->content < (*stack)->next->next->content)
				sa(stack);
			if ((*stack)->content > (*stack)->next->content
				&& (*stack)->content > (*stack)->next->next->content)
				ra(stack);
		}
	}
}
