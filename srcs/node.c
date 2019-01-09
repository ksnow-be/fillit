/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:30:25 by sbruen            #+#    #+#             */
/*   Updated: 2019/01/07 20:35:50 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char	**new_map(int size)
{
	int		x;
	int		y;
	char	**map;

	map = (char**)malloc(sizeof(char*) * (size + 1));
	x = 0;
	while (x < size)
	{
		map[x] = ft_strnew(size);
		x++;
	}
	map[x] = NULL;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		x++;
	}
	return (map);
}

t_tetra	*create_node(char *res)
{
	int		i;
	int		count;
	char	a;
	t_tetra	*tmp;
	t_tetra *node;

	count = count_tetro(res);
	i = 0;
	a = 'A';
	while (i < count)
	{
		if (i == 0)
			node = new_list_fillit(res, a);
		else
		{
			tmp = new_list_fillit(res, a);
			node = add_list(node, tmp);
		}
		i++;
		res += 21;
		a++;
	}
	while (node->prev)
		node = node->prev;
	return (node);
}

t_tetra	*list_filler(char **map, t_tetra *new)
{
	int		x;
	int		y;

	x = 0;
	new->map = ft_map_malloc();
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			new->map[x][y] = map[x][y];
			y++;
		}
		x++;
	}
	new->x = 0;
	new->y = 0;
	new->height = g_col;
	new->width = g_row;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_tetra	*new_list_fillit(char *res, char a)
{
	t_tetra	*new;
	char	*tmp;
	char	**map;

	tmp = ft_strsub(res, 0, 21);
	map = ft_strsplit(tmp, '\n');
	map = ft_cutter(map);
	new = (t_tetra *)malloc(sizeof(t_tetra));
	if (!new)
		return (NULL);
	new = list_filler(map, new);
	new->let = a;
	char_change(new->map, new->let, g_col, g_row);
	return (new);
}

t_tetra	*add_list(t_tetra *alst, t_tetra *new)
{
	alst->next = new;
	new->prev = alst;
	new->next = NULL;
	return (new);
}
