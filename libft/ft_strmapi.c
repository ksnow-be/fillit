/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:21:28 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/25 16:31:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			k;
	char			*str;

	i = 0;
	if (s && f)
	{
		k = ft_strlen(s);
		str = (char *)malloc(sizeof(*s) * k + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
