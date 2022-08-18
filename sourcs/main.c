/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/17 18:42:48 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("value = %d\n", stack->content);
		stack = stack->next;
	}
}

t_stack	*fill_stack(char **argv)
{
	t_stack	*stack;
	int		index;
	int		letter;

	stack = NULL;
	index = 0;
	while (argv[++index])
	{
		letter = -1;
		while (argv[index][++letter])
		{
			if (!ft_isdigit(argv[index][letter]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		ft_stkadd_back(&stack, ft_stknew(ft_atoi(argv[index])));
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc > 2)
	{
		stack_a = fill_stack(argv);
		print_stack(stack_a);
	}
	return (0);
}
