/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:02:36 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/12/03 17:03:34 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_word_filler(const char *s, char c, int *i)
{
	char	*res;
	int		j;

	j = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (!res)
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		res[j] = s[*i];
		j++;
		*i += 1;
	}
	res[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (res);
}
