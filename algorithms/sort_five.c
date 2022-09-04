/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 05:05:34 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 20:31:11 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	position_more(t_stack *stack)
{
	int			position;
	static int	index = 1;

	position = 0;
	while (stack)
	{
		position++;
		if (stack->index == index)
			break ;
		stack = stack->next;
	}
	index++;
	return (position);
}

void	share_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	count;
	int	tmp;

	count = size - 4;
	while (count--)
	{
		tmp = position_more(*stack_a);
		if (tmp >= 3)
		{
			tmp = size - tmp;
			while (tmp--)
				rra(stack_a);
		}
		else
		{
			while (--tmp)
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		size--;
	}
}

void	sort_five(t_stack **stack_a, int size)
{
	t_stack	*stack_b;

	stack_b = NULL;
	share_stack(stack_a, &stack_b, size + 1);
	if (size == 4)
		sort_two(stack_a);
	sort_three(stack_a, 0);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}
