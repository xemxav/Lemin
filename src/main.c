/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 14:12:48 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/17 12:22:01 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_text(t_info *info)
{
	ft_printf("%s\n", info->stock);
	ft_strdel(&info->stock);
	ft_printf("\n");
}

static char		*record_line(char *line,
				t_rm *anthill, t_info *info)
{
	char		*tmp;
	char		*tmp2;

	if (!(is_correct_line(line, anthill, info->f)))
	{
		info->ok = 0;
		return (info->stock);
	}
	if (info->stock == NULL)
		return (ft_strdup(line));
	tmp = ft_strdup(info->stock);
	tmp2 = ft_strjoin(info->stock, "\n");
	ft_strdel(&info->stock);
	info->stock = ft_strjoin(tmp2, line);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (info->stock);
}

t_rm			*parsing(t_info *inf, t_rm *anthill)
{
	char	*line;

	line = NULL;
	while (inf->f != -2 && get_next_line(0, &line))
	{
		inf->stock = record_line(line, anthill, inf);
		if ((*line != '#' || !ft_strcmp(line, "##start")
		|| !ft_strcmp(line, "##end")) && inf->ok == 1)
		{
			if ((inf->f = check_line(inf, line, inf->f)) < 0)
			{
				ft_strdel(&line);
				if (inf->f == -1)
					free_n_exit(anthill, NULL, 1);
				else
					return (anthill);
			}
			if (inf->f == 20 || inf->f == 10 || inf->f == 12 || inf->f == 14)
				anthill = record_anthill(anthill, line, inf->f);
		}
		ft_strdel(&line);
		if (inf->ok == 0)
			break ;
	}
	return (anthill);
}

static void		init_info(t_info *info)
{
	info->ant_cnt = 0;
	info->f = 0;
	info->ok = 1;
	info->stock = NULL;
}

int				main(int argc, char **argv)
{
	t_info		info;
	t_rm		*anthill;
	t_map		*map;

	(void)argv;
	anthill = NULL;
	map = NULL;
	if (argc > 1)
		free_n_exit(NULL, NULL, 1);
	init_info(&info);
	if ((anthill = parsing(&info, anthill)) == NULL)
		free_n_exit(anthill, map, 1);
	if ((map = get_paths(map, anthill)) == NULL)
	{
		ft_strdel(&info.stock);
		free_n_exit(anthill, map, 1);
	}
	print_text(&info);
	move_ants(anthill, map, &info);
	free_n_exit(anthill, map, 0);
	return (0);
}
