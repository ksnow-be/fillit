/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:51:09 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/27 15:48:18 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_strlen_my(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen_my(dst);
	srclen = ft_strlen_my(src);
	if (size <= dstlen)
		return (srclen + size);
	while (dst[i] && i < (size - 1))
		i += 1;
	while (*src && i < (size - 1))
	{
		dst[i] = *src;
		i += 1;
		src++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
