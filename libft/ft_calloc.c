/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:17:19 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/09 14:19:31 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*rtn;
	int		result;

	if (!nitems || !size)
		return (NULL);
	result = nitems * size;
	if ((result / nitems) != size)
		return (NULL);
	rtn = malloc(nitems * size);
	if (!rtn)
		return (NULL);
	ft_memset(rtn, 0, nitems * size);
	return (rtn);
}
