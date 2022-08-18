/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:37:05 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/04 02:55:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	end_str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	end_str = ft_strlen(&s[start]);
	if (end_str <= len)
		sub_str = (char *) malloc(end_str + 1);
	else
		sub_str = (char *) malloc (len + 1);
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len + 1);
	return (sub_str);
}
