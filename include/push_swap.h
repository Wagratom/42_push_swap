/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:41:10 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/08/22 11:15:41 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>


typedef struct data
{
	char	**argv;
	int		argc;
	int		*aux;
}	t_data;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//					steck
t_stack	*ft_stknew(int content);
t_stack	*ft_stklast(t_stack *lst);
void	ft_stkadd_back(t_stack **lst, t_stack *new);

void	print_stack(t_stack *stack);

//					auxiliaries
void	my_error(t_stack *stack);
int		valid_stack(t_stack *tack);
void	sort_three(t_stack **stack);
void	orde_aux(t_data *data);

void	sort_four(t_stack **stack, t_data *data);
//					sorts

/* sa (swap a): Troca os 2 primeiros elementos no topo da pilha a.
Não faça nada se houver apenas um ou nenhum elemento. */
void	sa(t_stack **stack_a);

/* sb (swap b): Troca os 2 primeiros elementos no topo da pilha b.
Não faça nada se houver apenas um ou nenhum elemento.*/
void	sb(t_stack **stack_b);

/* ss : sa e sb ao mesmo tempo. */
void	ss(t_stack **stack_a, t_stack **stack_b);

/* pa (pressione a): Pegue o primeiro elemento no topo de b e coloque-o no
topo de a. Não faça nada se b estiver vazio. */
void	pa(t_stack **stack_a, t_stack **stack_b);

/* pb (push b): Pegue o primeiro elemento no topo de a e coloque-o no topo
de b. Não faça nada se a estiver vazio. */
void	pb(t_stack **stack_a, t_stack **stack_b);

/* ra (girar a): Deslocar todos os elementos da pilha a por 1.
O primeiro elemento torna-se o último. */
void	ra(t_stack **stack_a);

/* rb (girar b): Desloca todos os elementos da pilha b por 1.
O primeiro elemento torna-se o último. */
void	rb(t_stack **stack_b);

/* rr : ra e rb ao mesmo tempo. */
void	rr(t_stack **stack_a, t_stack **stack_b);

/* rra (rotação reversa a): Desloca todos os elementos da pilha a por 1.
O último elemento torna-se o primeiro. */
void	rra(t_stack **stack_a);

/*rrb (rotação reversa b): Desloca todos os elementos da pilha b por 1.
O último elemento torna-se o primeiro */
void	rrb(t_stack **stack_b);

/* rrr: rra e rrb ao mesmo tempo */
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
