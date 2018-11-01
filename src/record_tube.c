/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   record_tube.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:54:46 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:00:15 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_tube		*connect_tube(t_rm *from, t_tube *new)
{
	t_tube			*tmp;

	if (from->tube == NULL)
		return (new);
	else
	{
		tmp = from->tube;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (from->tube);
}

t_rm				*record_tube(t_rm *anthill, char *sfrom, char *sto)
{
	t_rm			*from;
	t_rm			*to;
	t_tube			*new;

	from = anthill;
	while (ft_strcmp(from->rm_name, sfrom) != 0)
		from = from->next;
	to = anthill;
	while (ft_strcmp(to->rm_name, sto) != 0)
		to = to->next;
	if ((new = malloc(sizeof(t_tube))) == NULL)
		return (NULL);
	new->lk_rm = to;
	new->next = NULL;
	from->tube = connect_tube(from, new);
	return (anthill);
}
