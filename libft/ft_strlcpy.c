/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:35:47 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/05 03:34:33 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_src;
	size_t	count;

	count = -1;
	s_src = ft_strlen(src);
	if (!size || !src)
		return (s_src);
	while (src[++count] && count < size -1)
		dst[count] = src[count];
	dst[count] = '\0';
	return (s_src);
}
