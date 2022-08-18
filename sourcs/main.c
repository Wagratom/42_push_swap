/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/18 16:32:52 by wjuneo-f         ###   ########.fr       */
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

	if (!argv[1])
		my_error(NULL);
	stack = NULL;
	index = 0;
	while (argv[++index])
	{
		letter = -1;
		while (argv[index][++letter])
		{
			if (!ft_isdigit(argv[index][letter]))
				my_error(stack);
		}
		ft_stkadd_back(&stack, ft_stknew(ft_atoi(argv[index])));
	}
	return (stack);
}

int	gira_gira(t_stack **stack)
{
	while((*stack)->next)
	{
		if ((*stack)->content < (*stack)->next->content)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}

int	sort_tiny(t_stack **stack)
{
	printf("content1 = %d\n", (*stack)->content);
	printf("content1 = %d\n",  (*stack)->next->content);
	printf("content1 = %d\n",  (*stack)->next->next->content);


	while (1)
	{
		printf("entrei\n");
		if (valid_stack(stack))
			break ;
		if ((int)(*stack)->content < (int)(*stack)->next->content)
		{
			printf("entrei rra\n");
			rra(stack);
		}
		if ((*stack)->content > (*stack)->next->content &&
			(*stack)->content < (*stack)->next->next->content)
			sa(stack);
		if ((*stack)->content > (*stack)->next->content &&
			(*stack)->content > (*stack)->next->next->content)
			rrb(stack);
	}
	print_stack(*stack);
	printf("\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = fill_stack(argv);

	print_stack(stack_a);
	printf("\n");
	if (argc == 4)
		sort_tiny(&stack_a);
	return (0);
}
