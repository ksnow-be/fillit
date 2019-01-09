/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:34:38 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/29 17:53:03 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while ((*tmp1 == *tmp2 && *tmp1 && ++i < n))
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
