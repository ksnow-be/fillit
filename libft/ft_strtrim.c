/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:38:44 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/25 19:37:17 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') \
			&& s[i])
		i++;
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n') \
			&& s[i])
		len--;
	str = ft_strsub(s, i, len - i);
	if (!str)
		return (NULL);
	return (str);
}
