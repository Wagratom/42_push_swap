/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:05:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/04 07:23:00 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack **stack, int size)
{
	if (size == 2)
		sort_two(stack);
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
