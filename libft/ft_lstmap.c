/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:56:59 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/03 23:58:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*init;

	if (!lst ||!f || !del)
		return (NULL);
	init = ft_lstnew(f(lst->content));
	if (!init)
		ft_lstclear(&init, del);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&init, del);
			return (NULL);
		}
		ft_lstadd_back(&init, new);
		lst = lst->next;
	}
	return (init);
}
