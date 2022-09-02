/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:05:21 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:05:24 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	size_stack(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

void	raddix_aux(t_stack **stack_a, t_stack **stack_b)
{
	int		houses;
	int		count;
	int		size_b;
	int		size_a;

	houses = -1;
	size_a = size_stack(*stack_a);
	while (valid_stack(*stack_a))
	{
		houses++;
		count = 0;
		while (count++ < size_a)
		{
			if (((*stack_a)->index >> houses) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		size_b = size_stack(*stack_b);
		while (size_b--)
			pa(stack_a, stack_b);
	}
}

void	raddix(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	raddix_aux(stack_a, &stack_b);
}
