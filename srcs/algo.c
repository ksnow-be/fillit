/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:35:32 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/01/07 20:18:26 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		check_borders(t_tetra *node, t_tetra t, int size)
{
	if (node->width + t.y > size && t.x < size + 1)
	{
		t.y = 0;
		t.x++;
	}
	else if (node->height + t.x > size || (t.x > size - 1 || t.y > size - 1))
		return (0);
	return (1);
}

void	again(t_tetra *node, char **map)
{
	tetra_del(node, map);
	node = node->next;
	node->x = 0;
	node->y = 0;
	node = node->prev;
}

int		check_map(char **map, t_tetra *node, int size, int *ints)
{
	t_tetra t;

	t = *node;
	while (ints[0] < node->height)
	{
		t.y = node->y;
		ints[1] = 0;
		while (ints[1] < node->width)
		{
			if ((map[t.x][t.y] == '.' || (map[t.x][t.y] != '.' &&
							node->map[ints[0]][ints[1]] == '.')) && t.y < size)
			{
				t.y++;
				ints[1]++;
			}
			else
				return (0);
		}
		t.x++;
		ints[0]++;
	}
	return (1);
}

int		check_fit(char **map, t_tetra *node, int size)
{
	int		ints[2];
	t_tetra	t;

	ints[0] = 0;
	t = *node;
	if (check_borders(node, t, size) == 0)
		return (0);
	if (check_map(map, node, size, ints) == 0)
		return (0);
	return (1);
}

int		solve(t_tetra *node, char **map, int size)
{
	if (!node)
		return (1);
	while (map[node->x])
	{
		node->y = 0;
		while (map[node->x][node->y])
		{
			if (check_fit(map, node, size))
			{
				fill(node, map);
				if (solve(node->next, map, size))
					return (1);
				else
					again(node, map);
			}
			node->y++;
		}
		node->x++;
	}
	return (0);
}
