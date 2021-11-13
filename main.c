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

int	check_content(t_map *map)
{
	map->coins = 0;
	map->exits = 0;
	map->pos = 0;
	map->i = 0;
	while (map->i < map->height)
	{
		map->j = 0;
		while (map->arr[map->i][map->j])
		{
			if (!ft_strchr("01CVEP", map->arr[map->i][map->j]))
				return (0);
			if (map->arr[map->i][map->j] == 'C')
				map->coins++;
			if (map->arr[map->i][map->j] == 'E')
				map->exits++;
			if (map->arr[map->i][map->j] == 'P')
				map->pos++;
			map->j++;
		}
		map->i++;
	}
	if (map->coins < 1 || map->exits < 1 || map->pos < 1)
		return (0);
	return (1);
}

int	check_edges(char *str, t_map *map)
{
	char	*tmp;

	tmp = map->arr[0];
	while (*tmp)
	{
		if (*tmp != '1')
			return (0);
		tmp++;
	}
	tmp = map->arr[map->height - 1];
	while (*tmp)
	{
		if (*tmp != '1')
			return (0);
		tmp++;
	}
	if (str[0] != '1')
		return (0);
	if (str[ft_strlen(str) - 1] != '1')
		return (0);
	if (!check_content(map))
		return (0);
	return (1);
}

int	check_map(t_map *tMap)
{
	int	count;
	int	i;
	int	nums;

	i = 0;
	tMap->arr = ft_split(tMap->contest, '\n');
	count = (int)ft_strlen(tMap->arr[i]);
	while (tMap->arr[i])
	{
		if (count == (int)ft_strlen(tMap->arr[i]))
			i++;
		else
			return (0);
	}
	nums = i - 1;
	tMap->width = count;
	tMap->height = i;
	if (!((tMap->width >= 3 && tMap->height >= 5) || \
		(tMap->width >= 5 && tMap->height >= 3) || \
			(tMap->width >= 4 && tMap->height >= 4)))
		return (0);
	while (--nums)
		if (!check_edges(tMap->arr[nums], tMap))
			return (0);
	return (1);
}

void	full_check(t_map *tmap, char *str)
{
	int	fd;
	int	rd;

	tmap->contest = ft_substr(str, ft_strlen(str) - 4, 4);
	rd = ft_strncmp(tmap->contest, ".ber", 4);
	free(tmap->contest);
	fd = open(str, O_RDONLY);
	if (fd < 0 || rd != 0)
	{
		printf("Incorrect map!\n");
		exit (1);
	}
	tmap->contest = malloc(10000);
	rd = (int)read(fd, tmap->contest, 10000);
	tmap->contest[rd] = '\0';
	if (!check_map(tmap))
	{
		printf("Incorrect map!\n");
		exit (1);
	}
}

int	main(int ac, char **ag)
{
	t_map	map;

	if (ac == 2)
	{
		full_check(&map, ag[1]);
		draw_map(&map);
		mlx_key_hook(map.win, actions, &map);
		mlx_hook(map.win, 17, 0, leave_game, &map);
		mlx_loop(map.mlx);
	}
	return (0);
}
