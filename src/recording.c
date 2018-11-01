/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recording.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 19:30:25 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:00:10 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_rm	*build(t_rm *anthill, t_rm *new)
{
	t_rm	*tmp;

	if (anthill == NULL)
	{
		anthill = new;
		return (new);
	}
	else
	{
		tmp = anthill;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (anthill);
}

t_rm		*record_room(t_rm *anthill, int type, char **tab)
{
	t_rm	*new;

	if ((new = malloc(sizeof(t_rm))) == NULL)
		return (NULL);
	new->rm_name = ft_strdup(tab[0]);
	new->type = type;
	new->visit = 0;
	new->mark = 0;
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->tube = NULL;
	new->next = NULL;
	anthill = build(anthill, new);
	return (anthill);
}

static int	is_unique_tube(char **tab, t_rm *anthill)
{
	t_rm	*tmp;
	t_tube	*tube;

	if (anthill == NULL)
		return (0);
	tmp = anthill;
	while (tmp != NULL && ft_strcmp(tab[0], tmp->rm_name) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	tube = tmp->tube;
	while (tube != NULL)
	{
		if (ft_strcmp(tab[1], tube->lk_rm->rm_name) == 0)
			return (0);
		tube = tube->next;
	}
	return (1);
}

void		free_tab(char **tab)
{
	int		y;

	y = 0;
	while (tab[y] != NULL)
		ft_strdel(&tab[y++]);
	free(tab);
}

t_rm		*record_anthill(t_rm *anthill, char *line, int type)
{
	char	**tab;

	if (type == 10 || type == 12 || type == 14)
	{
		if ((tab = ft_strsplit(line, ' ')) == NULL)
			return (NULL);
		anthill = record_room(anthill, type, tab);
	}
	if (type == 20)
	{
		if ((tab = ft_strsplit(line, '-')) == NULL)
			return (NULL);
		if (is_unique_tube(tab, anthill))
		{
			anthill = record_tube(anthill, tab[0], tab[1]);
			anthill = record_tube(anthill, tab[1], tab[0]);
		}
	}
	free_tab(tab);
	return (anthill);
}
