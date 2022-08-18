/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:27:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/05/31 16:27:56 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	c = (char)c;
	while (*str)
	{
		if (*(unsigned char *)str == c)
			return ((char *)str);
		str++;
	}
	if (*(unsigned char *)str == c)
		return ((char *)str);
	return (NULL);
}
