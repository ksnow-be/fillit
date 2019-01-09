/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:53:27 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/01/09 11:09:32 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 700

# include "libft/libft.h"
# include <fcntl.h>

int		g_col;
int		g_row;
typedef struct		s_tetra
{
	int				x;
	int				y;
	int				height;
	int				width;
	char			let;
	char			**map;
	struct s_tetra	*next;
	struct s_tetra	*prev;
}					t_tetra;

int					check_fit(char **map, t_tetra *node, int size);
int					check_hor(char **str, int x);
int					check_vert(char **str, int y);
int					count_basic(char *res, int dotki, int cages, int slash);
int					count_tetro(char *res);
int					ft_basic_valid(char *res);
int					ft_sqrt(int nb);
int					ft_tetra_valid(char *res);
int					ft_valid_final(char *res);
int					tetra_height(char **str);
int					tetra_width(char **str);
int					solve(t_tetra *node, char **map, int size);
int					*tetra_coord(char **str, int *arr, int x, int y);
char				**ft_cutter(char **map);
char				**ft_map_malloc(void);
char				**new_map(int size);
void				char_change(char **map, char c, int height, int width);
void				fill(t_tetra *node, char **map);
void				ft_colrow(char **map);
void				ft_error(void);
void				ft_exit(char *res);
void				ft_print(char **res);
void				tetra_del(t_tetra *node, char **map);
void				ft_delete(t_tetra *node, char **map, int size);
t_tetra				*add_list(t_tetra *alst, t_tetra *new);
t_tetra				*create_node(char *res);
t_tetra				*new_list_fillit(char *tetra, char a);

#endif
