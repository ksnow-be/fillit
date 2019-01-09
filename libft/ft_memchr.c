/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:49:07 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/27 13:48:28 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned const char		*tmp;
	unsigned char			p;

	tmp = (unsigned const char *)s;
	p = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == p)
			return ((void *)&tmp[i]);
		i += 1;
	}
	return (NULL);
}
