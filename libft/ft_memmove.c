/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/03 19:26:37 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*str;

	if (!dest && !src)
		return (dest);
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*dst++ = *str++;
	}
	else
	{
		dst += n;
		str += n;
		while (n--)
			*--dst = *--str;
	}
	return (dest);
}
