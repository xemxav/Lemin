/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_correct_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 16:01:27 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:00:56 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	is_unique_room(char **tab, t_rm *anthill)
{
	t_rm	*tmp;

	if (anthill == NULL)
		return (1);
	tmp = anthill;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->rm_name, tab[0]) == 0)
			return (0);
		if (tmp->x == ft_atoi(tab[1]) && tmp->y == ft_atoi(tab[2]))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int	is_room(char *line, t_rm *anthill)
{
	int		valid;
	char	**tab;

	valid = 0;
	if (ft_strchr(line, ' ') != NULL && *line != 'L')
		valid++;
	else
		return (valid);
	if ((tab = ft_strsplit(line, ' ')) != NULL)
		valid++;
	else
		return (valid);
	if (tab[0] != NULL && tab[1] != NULL && tab[2] != NULL && tab[3] == NULL)
	{
		valid++;
		if ((ft_strisdigit(tab[1])) && (ft_strisdigit(tab[2])))
			valid++;
		if (is_unique_room(tab, anthill))
			valid++;
	}
	free_tab(tab);
	return (valid);
}

static int	has_good_connection(char *name, t_rm *anthill)
{
	t_rm	*tmp;

	tmp = anthill;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->rm_name, name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static	int	is_good_tube(char *line, t_rm *anthill)
{
	int		valid;
	char	**tab;

	valid = 0;
	if (ft_strchr(line, '-') != NULL)
		valid++;
	else
		return (valid);
	if ((tab = ft_strsplit(line, '-')) != NULL)
		valid++;
	else
		return (valid);
	if (tab[0] != NULL && tab[1] != NULL && tab[2] == NULL
	&& ft_strcmp(tab[0], tab[1]) != 0)
		valid++;
	else
		return (valid);
	if (has_good_connection(tab[0], anthill))
		if (has_good_connection(tab[1], anthill))
			valid++;
	free_tab(tab);
	return (valid);
}

int			is_correct_line(char *line, t_rm *anthill, int fwd)
{
	if (*line == '#')
		return (1);
	if (fwd == 0 && (ft_strisdigit(line)))
		return (1);
	if (is_room(line, anthill) == 5)
		return (1);
	if (is_good_tube(line, anthill) == 4)
		return (1);
	return (0);
}
