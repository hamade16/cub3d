/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:03:36 by houbeid           #+#    #+#             */
/*   Updated: 2020/11/29 12:03:45 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# define cub 32

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

double angle;
void *mlx_ptr;
void *win_ptr;
void *img_ptr;
int *pxl_ptr;
float xplayer;
float yplayer;
int width;
int height;
char **map;
int map_rows;
int map_clumns;
int fd;
char *line;
int compt;
char c;
float rotationangle;
int xline;
int yline;
int turndirection;
int walkdirection;
int movestep;
float newplayerx;
float newplayery;
float fov;
float rayangle;
int num_rays;

//
#include <stdlib.h>
#include <string.h>
//
void	ft_putchar(char c);
//int main(int argc, char *argv[]);
int	ft_atoi(const char *str);
static	int		ft_count_split(char const *str, char c);
static	int		ft_wsp(char const *str, int i, char c);
static	void	*free_t(char **split, int j);
char			**ft_split(char const *s, char c);
int	result(int i, const char *str, int sign);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void  ft_err(char *s);
int		is_empty(char *s);
void  ft_check_zero(char **map);
void	ft_putstr(char *s);
int    check_identfierR(char *l);
int ft_strchr2(char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
int		get_next_line1(int fd, char *buff, char **line, char **res);
int		free_m(char *str, int c);
int		res_ex(char **line, char **res, char *ptr);
int		retourne(int i, char **res);
int		get_next_line(int fd, char **line);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isdigit(int c);
void  drawcub(int x, int y, int color);
void	vision_N(int color);
void	vision_S(int color);
void	vision_W(int color);
void	vision_E(int color);
void	vision(int color);
#endif
