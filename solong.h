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

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_person {
	int			x;
	int			y;
	int			steps;
	char		*numstep;
}				t_character;

typedef struct s_map {
	int			height;
	int			width;
	char		*contest;
	char		**arr;
	int			size_im;
	void		*win;
	void		*mlx;
	t_character	monkey;
	t_character	portal;
	void		*wall;
	void		*bg;
	void		*enemy;
	void		*exit;
	void		*sprite;
	void		*apple;
	void		*door;
	void		*left;
	void		*right;
	void		*up;
	int			collects;
	int			x_;
	int			y_;
	int			end;
	int			i;
	int			j;
	int			coins;
	int			exits;
	int			pos;
}				t_map;

//split && check
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
int		ft_strchr(const char *s, int c);

//draw
void	draw_map(t_map *map);

//controller
int		leave_game(t_map *map);
int		actions(int k_code, t_map *map);

//moves
void	move_bg(t_map *map, int x, int y, void *img);
void	move_collects(t_map *map, int x, int y, void *img);
void	move_exit(t_map *map, int x, int y, void *img);
void	move_enemy(t_map *map);

#endif
