/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validacions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/08/22 13:50:24 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/09/02 10:53:22 by wwallas-         ###   ########.fr       */
=======
/*   Created: 2022/08/28 05:07:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/28 05:07:12 by wwallas-         ###   ########.fr       */
>>>>>>> b25dff4a4193a96017cd2300a2403a9247b8b336
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

int	repeat(char **argv)
{
	int	index;

	index = 0;
	while (argv[++index])
	{
		if (!ft_strncmp(argv[0], argv[index], ft_strlen(argv[index])))
			return (1);
	}
	return (0);
}
