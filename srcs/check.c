/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:40:21 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/01/07 20:18:53 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

int		ft_valid_final(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_basic_valid(res) == 0)
		return (0);
	while (res[i])
	{
		i++;
		if (res[i - 1] == '\n' && res[i] == '\n')
		{
			tmp = ft_strsub(res, 0, i - 1);
			if (ft_tetra_valid(tmp) == 0)
				return (0);
			res += 21;
			i = 0;
		}
		if (!res[i])
		{
			tmp = ft_strsub(res, 0, i - 1);
			if (ft_tetra_valid(tmp) == 0)
				return (0);
		}
	}
	return (1);
}

int		ft_tetra_valid(char *res)
{
	int		i;
	int		j;
	int		touches;
	char	**map;

	map = ft_strsplit(res, '\n');
	j = 0;
	touches = 0;
	while (map[j])
	{
		i = -1;
		while (++i < 4)
		{
			if ((map[j][i] == '#') && (i != 0) && (map[j][i - 1] == '#'))
				touches++;
			if ((map[j][i] == '#') && (i != 3) && (map[j][i + 1] == '#'))
				touches++;
			if ((map[j][i] == '#') && (j != 0) && (map[j - 1][i] == '#'))
				touches++;
			if ((map[j][i] == '#') && (j != 3) && (map[j + 1][i] == '#'))
				touches++;
		}
		j++;
	}
	return ((touches == 6 || touches == 8) ? 1 : 0);
}

void	ft_exit(char *res)
{
	int	i;

	i = 0;
	while (*res)
	{
		if (*res == '\n' && *(res + 1) == '\n')
		{
			i++;
			res++;
		}
		else
			res++;
	}
	if (i > 25)
		ft_error();
}

int		count_basic(char *res, int dotki, int cages, int slash)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (res[i] == '.')
			dotki++;
		else if (res[i] == '#')
			cages++;
		else if (res[i] == '\n')
			slash++;
		i++;
	}
	if (dotki != 12 || cages != 4 || slash != 4)
		return (0);
	else
		return (i);
}

int		ft_basic_valid(char *res)
{
	char	*tmp;
	int		dotki;
	int		cages;
	int		slash;

	slash = 0;
	dotki = 0;
	cages = 0;
	ft_exit(res);
	if (!count_basic(res, dotki, cages, slash))
		return (0);
	if (res[count_basic(res, dotki, cages, slash)] != '\0')
	{
		tmp = ft_strdup(res + 21);
		return (ft_basic_valid(tmp));
	}
	return (1);
}
