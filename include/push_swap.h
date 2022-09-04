/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:41:10 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/09/02 20:30:25 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//					algorithms
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack, int size);
void	sort_five(t_stack **stack, int size);
void	raddix(t_stack **stack_a);

//					stk
t_stack	*ft_stknew(int content);
t_stack	*ft_stklast(t_stack *lst);
void	ft_stkadd_back(t_stack **lst, t_stack *new);

//					auxiliaries
void	fill_stack(char	**argv, t_stack **stack_a);
void	find_index(t_stack **stack_a);
int		ft_is_int_nbr(char *nbr);
void	print_stack(t_stack *stack);
void	my_clear(t_stack *stack, int flg);

//					validacions
int		valid_stack(t_stack *tack);
int		repeat(char **argv);

//					sorts

/*
	sa (swap a)
	Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	sa(t_stack **stack_a);

/*
	sb (swap b)
	Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements
*/
void	sb(t_stack **stack_b);

/*
	ss : sa and sb at the same time.
*/
void	ss(t_stack **stack_a, t_stack **stack_b);

/*
	pa (push a)
	Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty
*/
void	pa(t_stack **stack_a, t_stack **stack_b);

/*
	pb (push b)
	Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
 */
void	pb(t_stack **stack_a, t_stack **stack_b);

/*
	ra (rotate a)
	Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ra(t_stack **stack_a);

/*
	rb (rotate b)
	Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/
void	rb(t_stack **stack_b);

/* rr : ra e rb ao mesmo tempo. */
void	rr(t_stack **stack_a, t_stack **stack_b);

/*
	rra (reverse rotate a)
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_stack **stack_a);

/*
	rrb (reverse rotate b)
	Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/
void	rrb(t_stack **stack_b);

/*
	rrr: rra and rrb at the same time.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
