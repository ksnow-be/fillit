/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:52:10 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/12/03 18:27:10 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**res;

	i = 0;
	j = 0;
	word = ft_word_count(s, c);
	res = (char **)malloc(sizeof(s) * word + 1);
	if (!res || !s)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < word && s[i])
	{
		res[j] = ft_word_filler(s, c, &i);
		if (!res[j])
		{
			ft_del(res, word);
			return (NULL);
		}
		j++;
	}
	res[j] = NULL;
	return (res);
}
