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

void	move_bg(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->win, map->bg,
		map->monkey.x * 64, map->monkey.y * 64);
	mlx_put_image_to_window(map->mlx, map->win, img, x * 64, y * 64);
	map->arr[map->monkey.y][map->monkey.x] = '0';
	map->monkey.steps++;
	map->monkey.numstep = ft_itoa(map->monkey.steps);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
	mlx_string_put(map->mlx, map->win, 32, 32, 255255255, map->monkey.numstep);
	free(map->monkey.numstep);
}

void	move_collects(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->win, map->bg,
		map->monkey.x * 64, map->monkey.y * 64);
	mlx_put_image_to_window(map->mlx, map->win, img, x * 64, y * 64);
	map->monkey.steps++;
	map->collects--;
	map->monkey.numstep = ft_itoa(map->monkey.steps);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
	mlx_string_put(map->mlx, map->win, 32, 32, 255255255, map->monkey.numstep);
	free(map->monkey.numstep);
	if (map->collects == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg,
			map->portal.x * 64, map->portal.y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			map->portal.x * 64, map->portal.y * 64);
	}
}

void	move_exit(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->win, map->bg,
		map->monkey.x * 64, map->monkey.y * 64);
	mlx_put_image_to_window(map->mlx, map->win, img, x * 64, y * 64);
	map->monkey.steps++;
	map->end = 1;
	map->monkey.numstep = ft_itoa(map->monkey.steps);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
	mlx_string_put(map->mlx, map->win, 32, 32, 255255255, map->monkey.numstep);
	free(map->monkey.numstep);
	leave_game(map);
}

void	move_enemy(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->bg,
		map->monkey.x * 64, map->monkey.y * 64);
	map->end = -1;
	map->monkey.steps++;
	map->monkey.numstep = ft_itoa(map->monkey.steps);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
	mlx_string_put(map->mlx, map->win, 32, 32, 255255255, map->monkey.numstep);
	free(map->monkey.numstep);
	leave_game(map);
}

int	leave_game(t_map *map)
{
	if (map->end == 0)
		printf("You left\n");
	else if (map->end == -1)
		printf("Movements: %d\nYou lost:(\n", map->monkey.steps);
	else if (map->end == 1)
		printf("Movements: %d\nYou won!\n", map->monkey.steps);
	mlx_destroy_window(map->mlx, map->win);
	exit (1);
}
