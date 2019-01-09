/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:25:20 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/12/03 16:32:35 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_spacer(str[i]) == 1)
		i++;
	if (ft_double_oper(str[i], str[i + 1]) == 1)
		return (0);
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
