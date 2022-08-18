/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:16 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/02 17:34:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!s1 || !s2 || !n)
		return (0);
	while ((s1[count] || s2[count]) && count < n - 1)
	{
		if (s1[count] != s2[count])
			return ((unsigned char) s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return ((unsigned char) s1[count] - (unsigned char)s2[count]);
}
