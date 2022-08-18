/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:13 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/08 20:30:08 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cpy;

	cpy = (unsigned char *)str;
	c = (unsigned char)c;
	while (n--)
	{
		if (*cpy == c)
			return ((void *)cpy);
		cpy++;
	}
	return (NULL);
}
