/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:02 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 09:27:20 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	data_init(char **argv, int argc, t_data *data)
{
	if (!argv[1])
		my_error(NULL);
	data->argv = argv;
	data->argc = argc - 1;
	data->aux = (int *)malloc(sizeof(int) * argc);
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

int	check_argv(char **argv)
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
		if (check_argv(&data->argv[index]))
			my_error(*stack_a);
		data->aux[index - 1] = ft_atoi(data->argv[index]);
		ft_stkadd_back(stack_a, ft_stknew(data->aux[index - 1]));
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_data	data;

	data_init(argv, argc, &data);
	fill_stack(&data, &stack_a);
	orde_aux(&data);
	while (data.argc--)
	{
		printf("%d\n", *data.aux);
		data.aux++;
	}
	if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 5)
		sort_five(&stack_a);
	print_stack(stack_a);
	return (0);
}
