/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:07:22 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/27 13:20:29 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		k;
	int			i;

	i = 0;
	if (s && f)
	{
		k = ft_strlen(s);
		str = (char *)malloc(sizeof(*s) * k + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		else
			return (NULL);
		return (str);
	}
	else
		return (NULL);
}
