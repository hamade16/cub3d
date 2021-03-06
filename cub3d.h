/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <houbeid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:03:36 by houbeid           #+#    #+#             */
/*   Updated: 2021/02/03 23:08:16 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "./minilibx/mlx.h"

# define FALSE 0
# define TRUE 1
# define CUB 64
# define WIDTH2 = width * CUB
# define FOV 60 * (M_PI / 180)



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
//float xline;
//float yline;
int turndirection;
int walkdirection;
int movestep;
float newplayerx;
float newplayery;
float fov;
float rayangle;
int num_rays;
float xintercept;
float yintercept;
float xstep;
float ystep;
float israyfacingdown;
float israyfacingup;
float israyfacingleft;
float israyfacingright;
float wallhitx;
float wallhity;
float nexthorzx;
float nexthorzy;
char **colorbuffer;
float distanceprojplane;
float projectwallheight;
float wallstripheight;
float walltoppixel;
float wallbottompixel;
float perpdistance;
float walkspeed;
float turnspeed;
float     texturoffsetX;
float     texturoffsetY;
float       distancefromtop;
void        *g_freetmp;
int         isRayFacingDown;
int         isRayFacingUp;
int         isRayFacingRight;
int         isRayFacingLeft;
int        *tmp;
//
#include <stdlib.h>
#include <string.h>
//
typedef struct s_point
{
    float x;
    float y;
}               t_point;

typedef struct s_rays
{
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
}               t_rays;



typedef struct    s_texture
{
    int            *north_texture;
    int            *south_texture;
    int            *east_texture;
    int            *west_texture;
}                  t_texture;

typedef struct  s_txt
{
    int         txt_width;
    int         txt_height;
    float       data;
}               t_txt;

t_texture        g_texture;
t_txt            g_txt;

typedef struct          s_sprite
{
    int			x;
	int			y;
	int			width;
	int			height;
	double		size;
	double		angle;
	double		it_x;
	double		it_y;
	double		distance;
}               t_sprt;

int             g_nbr_sprite;
int             *sp_file;
t_sprt          g_sprt[10000];

struct          s_map 
{
    int         colf;
    int         colc;
}               t_map;

struct          s_player 
{
    char        dir;
    float       ang;
}               t_player;

t_rays rays[INT_MAX];
typedef         struct s_texturedata
{
    char                *path;
    void                *img;
    int                 *addr;
}                       t_texdata;


void fetch_sp(char *str);
void fetch_we(char *str);
void fetch_ea(char *str);
void fetch_so(char *str);
int *fetch_texture(int iex);
void fetch_no(char *str);
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
void  drawcub(float x, float y, int width, int height, int color);
void	vision_N(int color);
void	vision_S(int color);
void	vision_W(int color);
void	vision_E(int color);
void	vision();
void	H_intersection(int color);
void castAllRays(int draw);
void    castRay(int stripId);
float       normalized_angle(float angle);
float       distancebetweenpoints(float x1, float y1, float x2, float y2);
void        drw_line(float x, float y, int color);
void        my_mlx_pixel_put(int x, int y, int color, void *img);
void		render();
int         haswallat(float newplayerx, float newplayery);
void        setup2();
void        draw_line(float x_one,float y_one,float x_zero,float y_zero);
int	        draw_txtur(	int *tmp,int txt_width);
int			setup(char *cubfile);
static char	**chkparams(char **pr);
static int	set_resolution(char **params);
static int	set_colors(char fp, char **params);
static int	set_texprite(char **params);
int		    validfile(char *file, char *ext);
int		    throwerror(char *error);
char	    *ft_resps(char *str, char c, short o);
char	    *clearspc(char *str);
int	        checkforin(int c, char *str);
int	        retfree(char *tmp1, char *tmp2, int ret);
int	        retfreetwo(char **tmp1, int ret);
int	        ft_lentwop(char **s);
int	        rgbtoint(int r, int g, int b);
int	        ft_isnumber(char *s);
int	        ft_isnbrcol(char *s);
int	        ft_isdigit(int c);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	    ft_lenfrom(int c, char *s);
static void	set_player(char dir, float x, float y);
int			checkmap(int lenx, int leny);
static int	addlinemap(int index, char *line, int lenx, int leny);
static int	mapsets(char *cubfile, int lenx, int leny);
int			set_map(char *cubfile, int fd, char *line);
char        *ft_strdup(const char *src);
char	    *ft_strtrim(char const *s1, char const *set);
int         ft_toupper(int c);
int         ft_tolower(int c);
int		    on_exit(void);
void        v_vision();
void		calcul_sprite(void);
void		sort_sprite(void);
#endif
