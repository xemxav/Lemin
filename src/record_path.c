/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   record_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 19:22:08 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:00:21 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_map				*choose_path(t_map *map, int ants)
{
	t_map			*tmp;
	int				dif;
	int				all;

	if (map->next == NULL)
		return (map);
	tmp = map;
	while (tmp->next != NULL)
	{
		dif = tmp->next->lenght - tmp->lenght;
		all = ants - tmp->lenght;
		ants = all;
		if (dif > all)
		{
			tmp = tmp->next;
			while (tmp != NULL)
			{
				tmp->lenght = 0;
				tmp = tmp->next;
			}
			break ;
		}
		tmp = tmp->next;
	}
	return (map);
}

static t_path		*new_room_path(t_path *path, t_rm *room)
{
	t_path			*new;
	t_path			*tmp;

	if ((new = malloc(sizeof(t_path))) == NULL)
		return (NULL);
	new->rm_adress = room;
	new->next = NULL;
	if (room->type == 10)
		room->visit = 1;
	if (path == NULL)
		return (new);
	tmp = path;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (path);
}

static int			is_new_path(t_map *map, t_path *path)
{
	t_map			*mtmp;
	t_path			*ptmp;
	t_path			*new;

	if (map == NULL)
		return (1);
	mtmp = map;
	new = path;
	while (mtmp->next != NULL)
		mtmp = mtmp->next;
	ptmp = mtmp->path;
	while (ptmp != NULL && new != NULL)
	{
		if (ptmp->rm_adress != new->rm_adress)
			return (1);
		ptmp = ptmp->next;
		new = new->next;
	}
	if ((ptmp == NULL && new != NULL) || (ptmp != NULL && new == NULL))
		return (1);
	return (0);
}

t_path				*record_path(t_bfs *cursor, t_map *map)
{
	t_path			*path;
	t_rm			*to_find;

	path = NULL;
	path = new_room_path(path, cursor->current);
	to_find = cursor->father;
	cursor = cursor->previous;
	while (cursor->father != NULL && cursor != NULL)
	{
		if (cursor->current == to_find)
		{
			path = new_room_path(path, cursor->current);
			to_find = cursor->father;
		}
		cursor = cursor->previous;
	}
	path = new_room_path(path, cursor->current);
	if (is_new_path(map, path))
		return (path);
	free_path(path);
	return (NULL);
}
