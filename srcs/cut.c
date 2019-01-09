/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:25:17 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/01/07 20:36:59 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		check_hor(char **str, int x)
{
	int		y;

	y = 0;
	while (y < 4)
	{
		if (str[x][y] == '.')
			y++;
		else
			break ;
	}
	if (y == 4)
		return (0);
	else
		return (1);
}

int		check_vert(char **str, int y)
{
	int		x;

	x = 0;
	while (x < 4)
	{
		if (str[x][y] == '.')
			x++;
		else
			break ;
	}
	if (x == 4)
		return (0);
	else
		return (1);
}

int		*tetra_coord(char **str, int *arr, int x, int y)
{
	int		x1;
	int		y1;

	arr = (int *)malloc(sizeof(int) * 4);
	x1 = x;
	y1 = y;
	while (!check_hor(str, x))
		x++;
	arr[0] = x;
	while (!check_vert(str, x1))
		x1++;
	arr[1] = x1;
	while (!check_hor(str, y))
		y--;
	arr[2] = y;
	while (!check_vert(str, y1))
		y1--;
	arr[3] = y1;
	return (arr);
}

char	**ft_cutter(char **map)
{
	int		x;
	int		y;
	int		tmp;
	int		*p;
	char	**res;

	p = NULL;
	x = 0;
	ft_colrow(map);
	res = ft_map_malloc();
	p = tetra_coord(map, p, 0, 3);
	while (p[0] <= p[2])
	{
		tmp = p[1];
		y = 0;
		while (tmp <= p[3])
		{
			res[x][y] = map[p[0]][tmp];
			tmp++;
			y++;
		}
		x++;
		p[0]++;
	}
	return (res);
}
