/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:02:51 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/09/02 11:52:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	my_clear(t_stack *stack, int flg)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
	if (flg)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	ft_is_int_nbr(char *nbr)
{
	char	*conversion;
	int		failure;

	failure = 0;
	conversion = ft_itoa(ft_atoi(nbr));
	if (ft_strncmp(conversion, nbr, ft_strlen(nbr) + 1))
		failure = 1;
	free(conversion);
	return (failure);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("value = %d\n", stack->content);
		stack = stack->next;
	}
	printf("\n");
}
