/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:07:12 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/28 19:21:46 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;

	tmp = NULL;
	if (size)
	{
		tmp = (unsigned char *)malloc(size);
		if (!tmp)
			return (NULL);
		while (size)
			tmp[--size] = 0;
	}
	return ((void *)tmp);
}
