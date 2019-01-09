/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:40:21 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/01/09 11:10:56 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [filename]");
	exit(1);
}

int		ft_sqrt(int nb)
{
	int		i;

	i = 2;
	if (nb > 0)
	{
		while (i < (nb / 2))
		{
			if (i * i == nb)
				return (i);
			else
				i++;
		}
	}
	else
		return (0);
	return (0);
}

void	ft_delete(t_tetra *node, char **map, int size)
{
	t_tetra	*tmp;

	tmp = node;
	ft_del(map, size);
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = NULL;
}

int		main(int argc, char **argv)
{
	int		fdrd[2];
	char	buff[601];
	t_tetra	*nodee;
	char	**map;
	int		size;

	if (argc != 2)
		ft_usage();
	fdrd[0] = open(argv[1], O_RDONLY);
	fdrd[1] = read(fdrd[0], buff, 600);
	buff[fdrd[1]] = '\0';
	if (ft_valid_final(buff) == 0)
		ft_error();
	size = ft_sqrt(count_tetro(buff) * 4);
	nodee = create_node(buff);
	map = new_map(size);
	while (!solve(nodee, map, size))
	{
		size++;
		nodee = create_node(buff);
		map = new_map(size);
	}
	ft_print(map);
	ft_delete(nodee, map, size);
	return (0);
}
