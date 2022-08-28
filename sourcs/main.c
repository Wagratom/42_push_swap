/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/25 12:57:01 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	fill_stack(char	**argv, t_stack **stack_a)
{
	int	index;
	int	aux;

	if (!argv[1])
		my_clear(NULL, 1);
	index = 0;
	*stack_a = NULL;
	while (argv[++index])
	{
		aux = -1;
		while (argv[index][++aux])
		{
			if (!ft_isdigit(argv[index][aux]))
				my_clear(*stack_a, 1);
		}
		if (valid_argv(&argv[index]))
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	fill_stack(argv, &stack_a);
	find_index(&stack_a);
	if (argc <= 4)
		sort_three(&stack_a, argc - 1);
	else if (argc <= 6)
		sort_five(&stack_a, argc - 1);
	else
		raddix(&stack_a);
	print_stack(stack_a);
	my_clear(stack_a, 0);
	return (0);
}
