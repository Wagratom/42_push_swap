/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validacions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:50:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 13:55:09 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

int	valid_argv(char **argv)
{
	int index;

	index = 0;
	while (argv[++index])
	{
		if (!ft_strncmp(argv[0], argv[index], ft_strlen(argv[index])))
			return (1);
	}
	return (0);
}
