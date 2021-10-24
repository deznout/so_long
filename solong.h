
#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

//debug
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct s_map {
	int 	height;
	int		width;
	char	*contest;
}				t_map;

typedef struct s_img {
	void *wall;
	void *bg;
	void *enemy;
	void *exit;
	void *sprite;
	void *apple;
}				t_img;

typedef struct	s_data {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif
