/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 14:13:13 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 17:59:40 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <stdio.h>

typedef struct		s_info
{
	int				ant_cnt;
	int				f;
	int				ok;
	char			*stock;
}					t_info;

typedef struct		s_tube
{
	struct s_rm		*lk_rm;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_bfs
{
	struct s_bfs	*next;
	struct s_bfs	*previous;
	struct s_rm		*father;
	struct s_rm		*current;
}					t_bfs;

typedef	struct		s_rm
{
	struct s_rm		*next;
	t_tube			*tube;
	int				type;
	int				visit;
	char			*rm_name;
	int				x;
	int				y;
	int				mark;
}					t_rm;

typedef struct		s_path
{
	struct s_rm		*rm_adress;
	struct s_path	*next;
}					t_path;

typedef struct		s_map
{
	struct s_path	*path;
	struct s_map	*next;
	int				lenght;
}					t_map;

typedef struct		s_stock
{
	struct s_rm		*start;
	struct s_rm		*end;
}					t_stock;

/*
** main.c
*/
t_rm				*parsing(t_info *info, t_rm *anthill);
/*
** is_correct_line.c
*/
int					is_correct_line(char *line, t_rm *anthill, int fwd);
/*
** check_line.c
*/
int					check_line(t_info *info, char *line, int fwd);
int					is_tube(char *line);
int					ft_strisdigit(char *s);

/*
** recording.c
*/
t_rm				*record_anthill(t_rm *anthill, char *line, int fwd);
t_rm				*record_room(t_rm *anthill, int type, char **tab);
t_rm				*record_tube(t_rm *anthill, char *sfrom, char *sto);
void				free_tab(char **tab);
/*
** free_n_exit.c
*/
t_rm				*free_anthill(t_rm *anthill);
t_tube				*free_tube(t_tube *tube);
t_path				*free_path(t_path *path);
t_map				*free_map(t_map *map);
void				free_n_exit(t_rm *anthill, t_map *map, int error);
/*
** bfs.c
*/
t_path				*bfs(t_stock *stock, t_map *map);
/*
** find_important.c
*/
t_rm				*find_start(t_rm *anthill);
t_rm				*find_end(t_rm *anthill);
int					unique_start(t_rm *anthill);
int					unique_end(t_rm *anthill);
/*
** get_paths.c
*/
t_map				*get_paths(t_map *map, t_rm *anthill);
/*
** record_path.c
*/
t_path				*record_path(t_bfs *cursor, t_map *map);
t_map				*choose_path(t_map *map, int ants);
/*
** move_ants.c
*/
void				move_ants(t_rm *anthill, t_map *map, t_info *infos);
#endif
