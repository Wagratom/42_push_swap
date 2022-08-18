/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:25 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/02 21:22:48 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	size_s2;

	size_s2 = ft_strlen(s2);
	if (!size_s2)
		return ((char *)s1);
	while (*s1 && size_s2 <= len--)
	{
		if (*s1 == *s2)
		{
			if (!ft_strncmp(s1, s2, size_s2))
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
