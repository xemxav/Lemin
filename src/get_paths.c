/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_paths.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 19:18:22 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:01:04 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_map		*reinit_visit(t_map *map)
{
	t_map			*tmp;
	t_path			*ptmp;

	tmp = map;
	while (tmp != NULL)
	{
		ptmp = tmp->path;
		while (ptmp != NULL)
		{
			ptmp->rm_adress->visit = 0;
			ptmp = ptmp->next;
		}
		tmp = tmp->next;
	}
	return (map);
}

static int			path_length(t_path *path)
{
	int				i;
	t_path			*tmp;

	i = 0;
	tmp = path;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static t_map		*record_path_in_map(t_path *path, t_map *map)
{
	t_map			*new;
	t_map			*tmp;

	if ((new = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	new->next = NULL;
	new->path = path;
	new->lenght = path_length(path);
	if (map == NULL)
		return (new);
	tmp = map;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (map);
}

static t_rm			*re_init_mark(t_rm *anthill)
{
	t_rm			*tmp;

	tmp = anthill;
	while (tmp != NULL)
	{
		tmp->mark = 0;
		tmp = tmp->next;
	}
	return (anthill);
}

t_map				*get_paths(t_map *map, t_rm *anthill)
{
	t_path			*new_path;
	t_stock			stock;

	if (!(unique_end(anthill)) || !(unique_start(anthill)))
		return (NULL);
	stock.start = find_start(anthill);
	stock.end = find_end(anthill);
	if (stock.start == NULL || stock.end == NULL)
		return (NULL);
	while ((new_path = bfs(&stock, map)) != NULL)
	{
		map = record_path_in_map(new_path, map);
		anthill = re_init_mark(anthill);
	}
	if (map == NULL)
		free_n_exit(anthill, map, 1);
	map = reinit_visit(map);
	return (map);
}
