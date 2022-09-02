/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:02:51 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/09/02 16:15:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	fill_stack(char	**argv, t_stack **stack_a)
{
	int	index;

	if (!argv[1])
		exit(0);
	*stack_a = NULL;
	index = 0;
	while (argv[++index])
	{
		if (ft_is_int_nbr(argv[index]))
			my_clear(*stack_a, 1);
		if (repeat(&argv[index]))
			my_clear(*stack_a, 1);
		ft_stkadd_back(stack_a, ft_stknew(ft_atoi(argv[index])));
	}
}

void	find_index(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = 1;
		tmp2 = *stack_a;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				tmp->index++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

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
