/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:02:51 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/21 18:32:20 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	my_error(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	valid_stack(t_stack *stack)
{
	int	index;

	index = 1;
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

void	orde_aux(t_data *data)
{
	int	index;
	int	tmp;
	int	cpy;

	cpy = data->argc;
	while (0 <= cpy--)
	{
		index = cpy;
		while (0 < index--)
		{
			if (data->aux[index] < data->aux[cpy])
			{
				tmp = data->aux[index];
				data->aux[index] = data->aux[cpy];
				data->aux[cpy] = tmp;
			}
		}
	}
}
