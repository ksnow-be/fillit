/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:28:00 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/27 09:22:51 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	while (size)
		tmp[--size] = '\0';
	return (tmp);
}
