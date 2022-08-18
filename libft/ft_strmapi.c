/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:04 by wwallas-          #+#    #+#             */
/*   Updated: 2022/05/31 16:36:07 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copy;
	unsigned int	index;

	copy = ft_strdup(s);
	index = -1;
	while (copy[++index])
		copy[index] = f(index, copy[index]);
	return (copy);
}
