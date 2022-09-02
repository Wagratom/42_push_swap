/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/09/02 16:22:26 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	order_stack(t_stack **stack, int argc)
{
	if (!valid_stack(*stack))
		return ;
	if (argc <= 4)
		sort_three(stack, argc - 1);
	else if (argc <= 6)
		sort_five(stack, argc - 1);
	else
		raddix(stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	fill_stack(argv, &stack_a);
	find_index(&stack_a);
	order_stack(&stack_a, argc);
	//print_stack(stack_a);
	my_clear(stack_a, 0);
	return (0);
}
