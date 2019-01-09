/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:28:11 by ksnow-be          #+#    #+#             */
/*   Updated: 2018/11/28 18:32:00 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (tmp1[i] && tmp2[i])
	{
		if (tmp1[i] == tmp2[i])
			i++;
		else
			return (tmp1[i] - tmp2[i]);
	}
	return (tmp1[i] - tmp2[i]);
}
