/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_line.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 17:39:46 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 18:01:18 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	ft_strisdigit(char *s)
{
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0' ? 1 : 0);
}

int	is_command(char *line)
{
	if (ft_strchr(line, ' ') != NULL && *line == 'L')
		return (-1);
	if (ft_strcmp(line, "##start") == 0)
		return (11);
	if (ft_strcmp(line, "##end") == 0)
		return (13);
	return (0);
}

int	is_tube(char *line)
{
	if (ft_strchr(line, '-') == NULL)
		return (0);
	return (1);
}

int	check_line(t_info *info, char *line, int fwd)
{
	int		ret;

	ret = 0;
	if (fwd == 0)
	{
		info->ant_cnt = ft_atoi(line);
		if (!ft_strisdigit(line) || info->ant_cnt <= 0)
			return (-1);
		return (1);
	}
	else if (fwd < 20)
	{
		if ((ret = is_command(line)) != 0 && fwd != 11 && fwd != 13)
			return (ret);
		else if (is_command(line))
			return (-1);
		else if (fwd == 11 || fwd == 13)
			return (fwd + 1);
		else if (is_tube(line))
			return (20);
		return (10);
	}
	if (!is_tube(line))
		return (-2);
	return (20);
}
