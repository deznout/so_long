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

void	init_map(t_map *map)
{
	map->end = -13;
	map->y_ = 0;
	map->collects = 0;
	map->monkey.steps = 0;
	map->size_im = 64;
	map->exit = mlx_xpm_file_to_image(map->mlx,
			"./img/exit.xpm", &map->size_im, &map->size_im);
	map->door = mlx_xpm_file_to_image(map->mlx,
			"./img/door.xpm", &map->size_im, &map->size_im);
	map->left = mlx_xpm_file_to_image(map->mlx,
			"./img/left.xpm", &map->size_im, &map->size_im);
	map->right = mlx_xpm_file_to_image(map->mlx,
			"./img/right.xpm", &map->size_im, &map->size_im);
	map->up = mlx_xpm_file_to_image(map->mlx,
			"./img/up.xpm", &map->size_im, &map->size_im);
	map->enemy = mlx_xpm_file_to_image(map->mlx,
			"./img/enemy.xpm", &map->size_im, &map->size_im);
	map->wall = mlx_xpm_file_to_image(map->mlx,
			"./img/wall.xpm", &map->size_im, &map->size_im);
	map->apple = mlx_xpm_file_to_image(map->mlx,
			"./img/apple.xpm", &map->size_im, &map->size_im);
	map->bg = mlx_xpm_file_to_image(map->mlx,
			"./img/bg.xpm", &map->size_im, &map->size_im);
	map->sprite = mlx_xpm_file_to_image(map->mlx,
			"./img/front.xpm", &map->size_im, &map->size_im);
}

void	draw_pers_and_ex(t_map *map)
{
	if (map->arr[map->y_][map->x_] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->sprite, map->x_ * 64, map->y_ * 64);
		map->monkey.x = map->x_;
		map->monkey.y = map->y_;
	}
	if (map->arr[map->y_][map->x_] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->door, map->x_ * 64, map->y_ * 64);
		map->portal.x = map->x_;
		map->portal.y = map->y_;
	}
}

void	draw_certain(t_map *map)
{
	if (map->arr[map->y_][map->x_] == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->wall, map->x_ * 64, map->y_ * 64);
	if (map->arr[map->y_][map->x_] != '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->bg, map->x_ * 64, map->y_ * 64);
	if (map->arr[map->y_][map->x_] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->apple, map->x_ * 64, map->y_ * 64);
		map->collects++;
	}
	draw_pers_and_ex(map);
	if (map->arr[map->y_][map->x_] == 'V')
		mlx_put_image_to_window(map->mlx, map->win,
			map->enemy, map->x_ * 64, map->y_ * 64);
}

void	draw_map(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width * 64,
			map->height * 64, "Monkey Jam!");
	init_map(map);
	while (map->y_ < map->height)
	{
		map->x_ = 0;
		while (map->x_ < map->width)
		{
			draw_certain(map);
			map->x_++;
		}
		map->y_++;
	}
	mlx_string_put(map->mlx, map->win, 32, 32, 255255255, "0");
}
