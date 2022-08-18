/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:55 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/04 03:41:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_str(char const *copy, char const *set, int size)
{
	int		count;
	int		flag;
	size_t	i;

	count = 0;
	copy += size;
	while (size--)
	{
		copy--;
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (*copy == set[i])
			{
				count++;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			return (count);
	}
	return (count);
}

static char	const	*start_check(char const *s1, char const *set)
{
	size_t	i;
	int		flag;

	while (*s1)
	{
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (*s1 == set[i])
				flag = 1;
			i++;
		}
		if (flag == 0)
			break ;
		s1++;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		del;

	s1 = start_check(s1, set);
	del = end_str(s1, set, ft_strlen(s1));
	result = ft_substr(s1, 0, (ft_strlen(s1) - del));
	if (!result)
		return (NULL);
	return (result);
}
