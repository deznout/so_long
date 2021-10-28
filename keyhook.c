/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:30:38 by hbrent            #+#    #+#             */
/*   Updated: 2021/10/28 14:30:51 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_up(t_map *map)
{
	if (map->arr[map->monkey.y - 1][map->monkey.x] == '1')
		return ;
	else if (map->arr[map->monkey.y - 1][map->monkey.x] == '0')
	{
		move_bg(map, map->monkey.x, map->monkey.y - 1, map->up);
		map->monkey.y--;
	}
	else if (map->arr[map->monkey.y - 1][map->monkey.x] == 'C')
	{
		move_collects(map, map->monkey.x, map->monkey.y - 1, map->up);
		map->monkey.y--;
	}
	else if (map->arr[map->monkey.y - 1][map->monkey.x] == 'E'
		&& map->collects == 0)
		move_exit(map, map->monkey.x, map->monkey.y - 1, map->up);
	else if (map->arr[map->monkey.y - 1][map->monkey.x] == 'V')
		move_enemy(map);
	printf("Movements: %d\n", map->monkey.steps);
}

void	move_left(t_map *map)
{
	if (map->arr[map->monkey.y][map->monkey.x - 1] == '1')
		return ;
	else if (map->arr[map->monkey.y][map->monkey.x - 1] == '0')
	{
		move_bg(map, map->monkey.x - 1, map->monkey.y, map->left);
		map->monkey.x--;
	}
	else if (map->arr[map->monkey.y][map->monkey.x - 1] == 'C')
	{
		move_collects(map, map->monkey.x - 1, map->monkey.y, map->left);
		map->monkey.x--;
	}
	else if (map->arr[map->monkey.y][map->monkey.x - 1] == 'E'
		&& map->collects == 0)
		move_exit(map, map->monkey.x - 1, map->monkey.y, map->left);
	else if (map->arr[map->monkey.y][map->monkey.x - 1] == 'V')
		move_enemy(map);
	printf("Movements: %d\n", map->monkey.steps);
}

void	move_down(t_map *map)
{
	if (map->arr[map->monkey.y + 1][map->monkey.x] == '1')
		return ;
	else if (map->arr[map->monkey.y + 1][map->monkey.x] == '0')
	{
		move_bg(map, map->monkey.x, map->monkey.y + 1, map->sprite);
		map->monkey.y++;
	}
	else if (map->arr[map->monkey.y + 1][map->monkey.x] == 'C')
	{
		move_collects(map, map->monkey.x, map->monkey.y + 1, map->sprite);
		map->monkey.y++;
	}
	else if (map->arr[map->monkey.y + 1][map->monkey.x] == 'E'
		&& map->collects == 0)
		move_exit(map, map->monkey.x, map->monkey.y + 1, map->sprite);
	else if (map->arr[map->monkey.y + 1][map->monkey.x] == 'V')
		move_enemy(map);
	printf("Movements: %d\n", map->monkey.steps);
}

void	move_right(t_map *map)
{
	if (map->arr[map->monkey.y][map->monkey.x + 1] == '1')
		return ;
	else if (map->arr[map->monkey.y][map->monkey.x + 1] == '0')
	{
		move_bg(map, map->monkey.x + 1, map->monkey.y, map->right);
		map->monkey.x++;
	}
	else if (map->arr[map->monkey.y][map->monkey.x + 1] == 'C')
	{
		move_collects(map, map->monkey.x + 1, map->monkey.y, map->right);
		map->monkey.x++;
	}
	else if (map->arr[map->monkey.y][map->monkey.x + 1] == 'E'
		&& map->collects == 0)
		move_exit(map, map->monkey.x + 1, map->monkey.y, map->right);
	else if (map->arr[map->monkey.y][map->monkey.x + 1] == 'V')
		move_enemy(map);
	printf("Movements: %d\n", map->monkey.steps);
}

int	actions(int k_code, t_map *map)
{
	if (k_code == 13)
		move_up(map);
	if (k_code == 0)
		move_left(map);
	if (k_code == 1)
		move_down(map);
	if (k_code == 2)
		move_right(map);
	if (k_code == 53)
	{
		map->end = 0;
		leave_game(map);
	}
	return (0);
}
