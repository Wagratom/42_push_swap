/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:30:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/05 14:44:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tot_str;
	size_t	tot_size;

	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	tot_str = (char *) malloc(tot_size);
	if (!tot_str)
		return (NULL);
	ft_strlcpy(tot_str, s1, ft_strlen(s1) +1);
	ft_strlcat(tot_str, (char *)s2, tot_size);
	return (tot_str);
}
