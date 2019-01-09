/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:09:07 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/29 17:51:40 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_my_strlen((const char *)s);
	while (i != 0 && s[i] != (char)c)
		i -= 1;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
