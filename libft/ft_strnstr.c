/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:37:17 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/27 21:07:11 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && ((i + j) < len))
			j += 1;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i += 1;
		j = 0;
	}
	if (needle[0] == '\0')
		return ((char *)&haystack[i]);
	return (NULL);
}
