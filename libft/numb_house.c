/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_house.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:37:39 by wwallas-          #+#    #+#             */
/*   Updated: 2022/07/27 17:51:13 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numb_house(unsigned long int nbr, int base)
{
	if (nbr < (unsigned long int)base)
		return (1);
	return (numb_house(nbr / base, base) + 1);
}
