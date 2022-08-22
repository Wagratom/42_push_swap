/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 14:34:18 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	data_init(char **argv, int argc, t_data *data)
{
	if (!argv[1])
		my_error(NULL);
	data->argv = argv;
	data->argc = argc - 2;
	data->aux = (int *)malloc(sizeof(int) * argc);
}

void	*fill_stack(t_data *data, t_stack **stack_a)
{
	int	index;
	int	aux;

	index = 0;
	*stack_a = NULL;
	while (data->argv[++index])
	{
		aux = -1;
		while (data->argv[index][++aux])
		{
			if (!ft_isdigit(data->argv[index][aux]))
				my_error(*stack_a);
		}
		if (valid_argv(&data->argv[index]))
			my_error(*stack_a);
		data->aux[index - 1] = ft_atoi(data->argv[index]);
		ft_stkadd_back(stack_a, ft_stknew(data->aux[index - 1]));
	}
}

void	orde_aux(t_data *data)
{
	int	index;
	int	tmp;
	int	cpy;

	cpy = -1;
	while (cpy++ < data->argc)
	{
		index = cpy;
		while (index++ < data->argc)
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_data	data;

	data_init(argv, argc, &data);
	fill_stack(&data, &stack_a);
	orde_aux(&data);
	if (argc <= 4)
		sort_three(&stack_a, argc - 1);
	else if (argc <= 6)
		sort_five(&stack_a, &data);
	print_stack(stack_a);
	return (0);
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
