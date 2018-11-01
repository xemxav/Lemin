/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 15:35:06 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:00:26 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_map	*take_out(t_map *road, t_stock *stock, int ants)
{
	t_path		*room;

	if (road->lenght == 0)
		return (road);
	room = road->path;
	if (room->next->rm_adress == stock->start)
	{
		while (stock->start->visit < 0)
		{
			ft_printf("L%d-%s ", stock->start->visit + ants + 1,
			stock->end->rm_name);
			stock->start->visit++;
		}
		return (NULL);
	}
	else if (room->next->rm_adress->visit != 0)
	{
		ft_printf("L%d-%s ", room->next->rm_adress->visit, stock->end->rm_name);
		room->next->rm_adress->visit = 0;
	}
	return (road);
}

static t_map	*take_from_start(t_map *road, t_rm *start, int ants)
{
	t_path		*tmp;

	if (road->lenght == 0)
		return (road);
	tmp = road->path;
	while (tmp->next != NULL && tmp->next->rm_adress != start)
		tmp = tmp->next;
	if (tmp->rm_adress->visit == 0 && start->visit < 0)
	{
		tmp->rm_adress->visit = tmp->next->rm_adress->visit + ants + 1;
		tmp->next->rm_adress->visit++;
		if (tmp->rm_adress->visit != 0)
			ft_printf("L%d-%s ", tmp->rm_adress->visit,
			tmp->rm_adress->rm_name);
	}
	return (road);
}

static t_map	*move_ants_fwd(t_map *road, t_stock *stock)
{
	t_path		*tmp;

	if (road->lenght == 0)
		return (road);
	tmp = road->path;
	while (tmp->next != NULL && tmp->next->rm_adress != stock->start
	&& tmp->next->rm_adress->visit == 0)
		tmp = tmp->next;
	if (tmp->next->rm_adress == stock->start)
		return (road);
	while (tmp->next != NULL && tmp->next->rm_adress != stock->start)
	{
		tmp->rm_adress->visit = tmp->next->rm_adress->visit;
		if (tmp->rm_adress->visit != 0)
			ft_printf("L%d-%s ", tmp->rm_adress->visit,
			tmp->rm_adress->rm_name);
		tmp = tmp->next;
	}
	tmp->rm_adress->visit = 0;
	return (road);
}

static int		i_get_ants(t_map *map)
{
	t_path		*p_tmp;
	t_map		*m_tmp;
	t_rm		*room;

	m_tmp = map;
	while (m_tmp != NULL)
	{
		p_tmp = m_tmp->path;
		while (p_tmp != NULL)
		{
			room = p_tmp->rm_adress;
			if (room->visit != 0 && room->type != 14)
				return (1);
			p_tmp = p_tmp->next;
		}
		m_tmp = m_tmp->next;
	}
	return (0);
}

void			move_ants(t_rm *anthill, t_map *map, t_info *infos)
{
	t_stock		stock;
	t_map		*road;

	stock.start = find_start(anthill);
	stock.end = find_end(anthill);
	stock.start->visit = -1 * infos->ant_cnt;
	map = choose_path(map, infos->ant_cnt);
	while (i_get_ants(map))
	{
		road = map;
		while (road != NULL)
		{
			if ((road = take_out(road, &stock, infos->ant_cnt)) == NULL)
				break ;
			road = move_ants_fwd(road, &stock);
			road = take_from_start(road, stock.start, infos->ant_cnt);
			road = road->next;
		}
		ft_putchar('\n');
	}
}
