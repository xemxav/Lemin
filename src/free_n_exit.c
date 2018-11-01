/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_n_exit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:28:43 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:01:08 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_rm		*free_anthill(t_rm *anthill)
{
	t_rm	*tmp;

	if (anthill == NULL)
		return (NULL);
	tmp = anthill->next;
	free_tube(anthill->tube);
	ft_memdel((void**)&(anthill->rm_name));
	ft_memdel((void**)&anthill);
	return (free_anthill(tmp));
}

t_tube		*free_tube(t_tube *tube)
{
	t_tube	*tmp;

	if (tube == NULL)
		return (NULL);
	tmp = tube->next;
	ft_memdel((void**)&tube);
	return (free_tube(tmp));
}

t_path		*free_path(t_path *path)
{
	t_path *tmp;

	if (path == NULL)
		return (NULL);
	tmp = path->next;
	ft_memdel((void**)&path);
	return (free_path(tmp));
}

t_map		*free_map(t_map *map)
{
	t_map *tmp;

	if (map == NULL)
		return (NULL);
	tmp = map->next;
	free_path(map->path);
	ft_memdel((void**)&map);
	return (free_map(tmp));
}

void		free_n_exit(t_rm *anthill, t_map *map, int error)
{
	free_anthill(anthill);
	free_map(map);
	if (error == 1)
		ft_printf("ERROR\n");
	exit(EXIT_SUCCESS);
}
