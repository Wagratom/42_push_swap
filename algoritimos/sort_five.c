/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:27:06 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/23 21:57:33 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	position_more(t_stack *stack, t_data *data, int posi)
{
	int	index;

	index = 0;
	while (stack)
	{
		index++;
		if (stack->content == data->aux[posi])
			return (index);
		stack = stack->next;
	}
	return (-1);
}

int	share_stack(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	count;
	int	tmp;
	int	aux;

	*stack_b = NULL;
	aux = data->argc -2;
	count = -1;
	while (++count < aux)
	{
		tmp = position_more(*stack_a, data, count);
		while (tmp != 1)
		{
			if (tmp >= 3)
				rra(stack_a);
			else
				ra(stack_a);
			tmp = position_more(*stack_a, data, count);
		}
		pb(stack_a, stack_b);
	}
	return (data->argc - 3);
}

void	sort_five(t_stack **stack_a, t_data *data)
{
	t_stack	*stack_b;
	int		tmp;

	tmp = share_stack(stack_a, &stack_b, data) + 1;
	if (tmp == 2)
	{
		if (stack_b->content < stack_b->next->content)
			sa(&stack_b);
	}
	sort_three(stack_a, 0);
	while (tmp--)
		pa(stack_a, &stack_b);
}
