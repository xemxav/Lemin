/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bfs.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 13:03:41 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 17:59:55 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_bfs		*new_bfs(t_bfs *cursor, t_rm *current, t_rm *father)
{
	t_bfs			*new;
	t_bfs			*tmp;

	if ((new = (t_bfs*)malloc(sizeof(t_bfs))) == NULL)
		return (NULL);
	if (father == NULL)
		new->father = NULL;
	else
		new->father = father;
	new->current = current;
	new->current->mark = 1;
	new->next = NULL;
	if (cursor == NULL)
	{
		new->previous = NULL;
		return (new);
	}
	tmp = cursor;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
	return (cursor);
}

static t_bfs		*free_queue(t_bfs *queue)
{
	t_bfs			*tmp;

	if (queue == NULL)
		return (NULL);
	tmp = queue->next;
	ft_memdel((void**)&queue);
	return (free_queue(tmp));
}

t_path				*bfs(t_stock *stock, t_map *map)
{
	t_bfs			*queue;
	t_bfs			*cursor;
	t_tube			*child;
	t_path			*new_path;

	queue = NULL;
	queue = new_bfs(queue, stock->start, NULL);
	cursor = queue;
	new_path = NULL;
	while (cursor != NULL && cursor->current != stock->end)
	{
		child = cursor->current->tube;
		while (child != NULL)
		{
			if (child->lk_rm->visit == 0 && child->lk_rm->mark == 0)
				cursor = new_bfs(cursor, child->lk_rm, cursor->current);
			child = child->next;
		}
		cursor = cursor->next;
	}
	if (cursor != NULL && cursor->current == stock->end)
		new_path = record_path(cursor, map);
	free_queue(queue);
	return (new_path);
}
