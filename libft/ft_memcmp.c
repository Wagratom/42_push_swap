/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:24 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/02 17:25:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str01;
	unsigned char	*str02;

	if (!n || !str2 || !str1)
		return (0);
	str01 = (unsigned char *)str1;
	str02 = (unsigned char *)str2;
	while (n--)
	{
		if (*str01 != *str02)
			return (*str01 - *str02);
		str01++;
		str02++;
	}
	return (0);
}
