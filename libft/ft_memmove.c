/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:24:02 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/26 20:29:49 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstc;
	const char	*srcc;
	size_t		i;

	i = 0;
	dstc = (char *)dst;
	srcc = (char *)src;
	if (srcc < dstc)
		while ((int)(--len) >= 0)
			*(dstc + len) = *(srcc + len);
	else
		while (i < len)
		{
			*(dstc + i) = *(srcc + i);
			i++;
		}
	return (dst);
}
