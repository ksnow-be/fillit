/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:22:01 by sbruen            #+#    #+#             */
/*   Updated: 2019/01/07 20:28:35 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	fill(t_tetra *node, char **map)
{
	int		x;
	int		y;

	x = 0;
	while (node->height > x)
	{
		y = 0;
		while (node->width > y)
		{
			if (node->map[x][y] != '.')
				map[x + node->x][y + node->y] = node->map[x][y];
			y++;
		}
		x++;
	}
}

void	tetra_del(t_tetra *node, char **map)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == node->let)
				map[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

int		tetra_height(char **str)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (str[x][y] == '#')
			{
				i++;
				break ;
			}
			y++;
		}
		x++;
	}
	return (i);
}

int		tetra_width(char **str)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (str[x][y] == '#')
			{
				i++;
				break ;
			}
			x++;
		}
		y++;
	}
	return (i);
}
