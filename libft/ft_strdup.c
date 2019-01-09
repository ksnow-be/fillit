/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:14:33 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/12/03 14:09:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(*dest) * i + 1);
	i = 0;
	if (dest)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	else
		return (NULL);
	dest[i] = '\0';
	return (dest);
}
