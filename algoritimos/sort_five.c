/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:27:06 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 13:27:07 by wjuneo-f         ###   ########.fr       */
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

void	share_stack(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	tmp;
	int	aux;

	*stack_b = NULL;
	aux = -1;
	while (++aux < 2)
	{
		tmp = position_more(*stack_a, data, aux);
		while (tmp != 1)
		{
			if (tmp >= 3)
				rra(stack_a);
			else
				ra(stack_a);
			tmp = position_more(*stack_a, data, aux);
		}
		pb(stack_a, stack_b);
	}
}

void	sort_four(t_stack **stack_a, t_data *data)
{
	t_stack	*stack_b;

	share_stack(stack_a, &stack_b, data);

	print_stack(*stack_a);
	printf("\n\n");
	print_stack(stack_b);
}
