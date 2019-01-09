/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:11:04 by sbruen            #+#    #+#             */
/*   Updated: 2019/01/07 20:12:36 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	ft_colrow(char **map)
{
	g_col = tetra_height(map);
	g_row = tetra_width(map);
}

char	**ft_map_malloc(void)
{
	int		i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(char*) * (g_col + 1));
	while (i < g_col)
	{
		str[i] = ft_strnew(g_row);
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	ft_print(char **res)
{
	int		x;

	x = 0;
	while (res[x])
	{
		ft_putendl(res[x]);
		x++;
	}
}

int		count_tetro(char *res)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (res[i])
	{
		if (res[i] == '#')
			a++;
		i++;
	}
	return (a / 4);
}

void	char_change(char **map, char c, int height, int width)
{
	int	y;
	int	x;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == '#')
				map[x][y] = c;
			y++;
		}
		x++;
	}
}
