/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:18:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/06/06 21:11:25 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_houses(long int n, int flg)
{
	int	i;

	i = 1;
	while (n >= 10 && i++)
		n /= 10;
	if (flg)
		i++;
	return (i);
}

static char	*convert_numb(int n, int flag)
{
	unsigned int	aux;
	int				size_n;
	char			*result;

	aux = n;
	if (flag)
		aux = -aux;
	size_n = n_houses(aux, flag) + 1;
	result = (char *) malloc(size_n);
	if (result == NULL)
		return (NULL);
	result[--size_n] = '\0';
	while (aux)
	{
		result[--size_n] = (aux % 10) + 48;
		aux /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		flag;

	flag = n < 0;
	result = convert_numb(n, flag);
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (flag)
		result[0] = '-';
	return (result);
}
