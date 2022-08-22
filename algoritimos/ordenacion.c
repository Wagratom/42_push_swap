/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenacion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:35:16 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 09:31:43 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_stack **stack)
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

int	position_more(t_stack **stack, t_data *data)
{
	int	index;

	index = 0;
	while (*stack)
	{
		if ()
		(*stack) = (*stack)->next;
	}
}
sort_four(t_stack **stack, t_data *data)
{
	int	index;

	index = 0;
	while(1)
	{
		index++;
		while(*stack)
		{
			if ()
			(*stack) = (*stack)->next;
		}
	}
}
