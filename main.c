#include "solong.h"

int worldMap[mapWidth][mapHeight]=
		{
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,0,0,0,0,2,1},
		{1,0,0,0,0,1,1,1,1,1,0,0,1},
		{1,3,0,0,1,1,4,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		};

//img.img = mlx_new_image(mlx, 1920, 1080);
//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

void	drawMap()
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int c = 0;
	int k = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Monkey Jam!");
	img.exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &c, &k);
	img.enemy = mlx_xpm_file_to_image(mlx, "./img/enemy.xpm", &c, &k);
	img.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &c, &k);
	img.apple = mlx_xpm_file_to_image(mlx, "./img/apple.xpm", &c, &k);
	img.bg = mlx_xpm_file_to_image(mlx, "./img/bg.xpm", &c, &k);
	img.sprite = mlx_xpm_file_to_image(mlx, "./img/sprite.xpm", &c, &k);
	for (int y = 0; y < mapHeight * 64; y += 64)
	{
		for (int x = 0; x < mapWidth * 64; x += 64)
		{
			if (worldMap[y/64][x/64] == 1)
				mlx_put_image_to_window(mlx, mlx_win, img.wall, x, y);
			if (worldMap[y/64][x/64] != 1)
				mlx_put_image_to_window(mlx, mlx_win, img.bg, x, y);
			if (worldMap[y/64][x/64] == 2)
				mlx_put_image_to_window(mlx, mlx_win, img.apple, x, y);
			if (worldMap[y/64][x/64] == 3)
				mlx_put_image_to_window(mlx, mlx_win, img.sprite, x, y);
			if (worldMap[y/64][x/64] == 4)
				mlx_put_image_to_window(mlx, mlx_win, img.exit, x, y);
		}
	}
	mlx_loop(mlx);
}

int	checkSize(t_map *tMap)
{
	
	return (0);
}

int	checkMap(t_map *tMap)
{
	int	i;

	i = 0;
	tMap->height = 0;
	while (tMap->contest[i] && tMap->contest[i] != '\n')
		i++;
	tMap->width = i;
	i = 0;
	while (tMap->contest[i])
	{
		if (tMap->contest[i] == '\n')
			tMap->height++;
		i++;
	}
	tMap->height++;
	if (checkSize(tMap))
		return (1);
	return (0);
}

int	main(int ac, char **ag)
{
	int	fd;
	int	readByte;
	t_map map;

	if (ac == 2)
	{
		fd = open(ag[1], O_RDONLY);
		map.contest = malloc(10000);
		readByte = read(fd, map.contest, 10000);
		map.contest[readByte] = '\0';
		if (!checkMap(map))
		{
			printf("Incorrect map!\n");
			return (0);
		}
	}
	return (0);
}
