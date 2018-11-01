/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   A_SUPPR.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 18:50:48 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/16 17:43:50 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	print_room(t_rm *room)
{
	t_rm	*tmp;

	tmp = room;
	ft_printf("rm_name =%s\n", tmp->rm_name);
	ft_printf("type =%d\n", tmp->type);
	ft_printf("visit =%d\n", tmp->visit);
	ft_printf("mark=%d\n", tmp->mark);
	ft_printf("x =%d\n", tmp->x);
	ft_printf("y =%d\n", tmp->y);
	print_tubes(tmp->tube);
	ft_printf("\n\n");
}

void	print_anthill(t_rm *anthill)
{
	t_rm *tmp;

	tmp = anthill;
	while (tmp != NULL)
	{
		print_room(tmp);
		tmp = tmp->next;
	}
}

void	print_tubes(t_tube *tube)
{
	t_tube	*tmp;
	int y = 1;

	tmp = tube;
	while (tmp != NULL)
	{
		ft_printf("tube numero %d\n", y++);
		print_tube(tmp);
		tmp = tmp->next;
	}
}

void	print_tube(t_tube *tube)
{
	t_tube	*tmp;
	
	tmp = tube;
	ft_printf("adresse room pointee, name = %s\n", tmp->lk_rm->rm_name);
}

void	print_path(t_path *path)
{
	t_path *tmp;
	int y = 1;

	tmp = path;
	while (tmp != NULL)
	{
		ft_printf("address %d = %s\n", y++, tmp->rm_adress->rm_name);
		tmp = tmp->next;
	}
}

void	print_map(t_map *map)
{
	t_map	*tmp;
	int y = 1;

	tmp = map;
	while (tmp != NULL)
	{
		ft_printf("path num %d\n", y++);
		print_path(tmp->path);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	print_one_bfs(t_bfs *bfs)
{
	ft_printf("debut print bfs\n");
	if (bfs->current != NULL)
	{
		ft_printf("room current = ");
		print_room(bfs->current);
	}
	if (bfs->father != NULL)
	{
		ft_printf("room father = ");
		print_room(bfs->father);
	}
	ft_printf("fin print bfs\n");
}

void print_all_bfs(t_bfs *bfs)
{
	t_bfs *tmp;

	tmp = bfs;
	while (tmp != NULL)
	{
		print_one_bfs(tmp);
		tmp = tmp->next;
	}
}

void print_cursor(t_bfs *cursor)
{
	if (cursor->father == NULL && cursor->current != NULL)
	{	
		ft_printf("<|f=NULL|c=%s|>", cursor->current->rm_name);
		return ;
	}
	if (cursor->father != NULL && cursor->current != NULL)
	{	
		ft_printf("<|f=%s||c=%s|>", cursor->father->rm_name, cursor->current->rm_name);
		return ;
	}
	if (cursor->father != NULL && cursor->current == NULL)
	{	
		ft_printf("<|f=%s||c=NULL|> ", cursor->father->rm_name);
		return ;
	}
}

void print_length(t_map *map) // a suppr
{
	t_map *tmp;

	tmp = map;
	while (tmp)
	{
		ft_printf("start by %s lenth = %d\n", tmp->path->rm_adress->rm_name, tmp->lenght);
		tmp = tmp->next;
	}
}