/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_important.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 19:15:49 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:01:15 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_rm		*find_start(t_rm *anthill)
{
	t_rm	*tmp;

	tmp = anthill;
	while (tmp != NULL && tmp->type != 12)
	{
		if (tmp->next == NULL && tmp->type != 12)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

t_rm		*find_end(t_rm *anthill)
{
	t_rm	*tmp;

	tmp = anthill;
	while (tmp != NULL && tmp->type != 14)
	{
		if (tmp->next == NULL && tmp->type != 14)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

int			unique_start(t_rm *anthill)
{
	t_rm	*tmp;
	int		nb;

	tmp = anthill;
	nb = 0;
	while (tmp != NULL)
	{
		if (tmp->type == 12)
			nb++;
		tmp = tmp->next;
	}
	if (nb != 1)
		return (0);
	return (1);
}

int			unique_end(t_rm *anthill)
{
	t_rm	*tmp;
	int		nb;

	tmp = anthill;
	nb = 0;
	while (tmp != NULL)
	{
		if (tmp->type == 14)
			nb++;
		tmp = tmp->next;
	}
	if (nb != 1)
		return (0);
	return (1);
}
