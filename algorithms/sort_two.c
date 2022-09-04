/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:29:52 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 20:30:10 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_two(t_stack **stack)
{
	int	first;
	int	second;

	first = (*stack)->content;
	second = (*stack)->next->content;
	if (first > second)
		sa(stack);
}
