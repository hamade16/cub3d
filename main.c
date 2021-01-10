#include "cub3d.h"
#include "mlx.h"
#define cub 32

void	map_file()
{
	char *mp;
	char *pfree;
	int    end;
	int i;
	int j;
	char **s;
	int a;
	int r;
	int b;
	int c;
	int d;
	int e;

	r = 0;
	i = 0;
	j = 0;
	mp = ft_strdup("\0");
	map_clumns = 0;
	map_rows = 1;
	compt = 0;
	
	// while (get_next_line(fd, line))
	// {
		
	// }
	while (get_next_line(fd, &line))
	{
		a = check_identfierR(line);
		if (a == 1)
			break;
		else
			continue;
	}
	if (a == 0)
		ft_err("error1");
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			continue;
		else
			break;
	}
	if (!ft_strchr2(line, '1'))
			ft_err("errormap1");
	pfree = mp;
	mp = ft_strjoin(mp, line);
	free(pfree);
	map_clumns = ft_strlen(line);
	while(get_next_line(fd, &line))
	{
		if (map_clumns < ft_strlen(line))
		{
			i = map_clumns;
			while (i < ft_strlen(line))
			{
				mp = ft_strjoin(mp, " ");
				i++;
			}
			mp = ft_strjoin(mp, "\n");
			map_clumns = ft_strlen(line);
			pfree = mp;
			mp = ft_strjoin(mp, line);
			free(pfree);
		}
		else
		{
			mp = ft_strjoin(mp, "\n");
			pfree = mp;
			mp = ft_strjoin(mp, line);
			free(pfree);
			i = ft_strlen(line);
			while (i < map_clumns)
			{
				pfree = mp;
				mp = ft_strjoin(mp, " ");
				free(pfree);
				i++;
			}
		}
		map_rows += 1;
		if (is_empty(line))
			ft_err("hello world\n");
	}
	if (map_clumns < ft_strlen(line))
	{
		i = map_clumns;
		while (i < ft_strlen(line))
		{
			mp = ft_strjoin(mp, " ");
			i++;
		}
		mp = ft_strjoin(mp, "\n");
		map_clumns = ft_strlen(line);
		pfree = mp;
		mp = ft_strjoin(mp, line);
		free(pfree);
			pfree = mp;
			mp = ft_strjoin(mp, "\n");
			free(pfree);
	}
	else
	{
		mp = ft_strjoin(mp, "\n");
		pfree = mp;
		mp = ft_strjoin(mp, line);
		free(pfree);
		i = ft_strlen(line);
		while (i < map_clumns)
		{
			pfree = mp;
			mp = ft_strjoin(mp, " ");
			free(pfree);
			i++;
		}
			pfree = mp;
			mp = ft_strjoin(mp, "\n");
			free(pfree);
	}
	map_rows += 1;
	map = ft_split(mp, '\n');
	ft_check_zero(map);
}

void  drawcub(float x, float y, int color)
{
	for (int i = x; i < x + CUB; i++)
	{
		for (int j = y; j < y + CUB; j++)
		{
			my_mlx_pixel_put(j, i, color, img_ptr);
			// pxl_ptr[i * (cub * map_clumns) + j] = color;
		}
	}
}

int found = 0;
void	player_p()
{
	int i;
	int j;

	i = 0;
	while (i < map_rows)
	{
		j = 0;
		while (j < map_clumns)
		{
			if (map[i][j] == 'N')
			{
				xplayer = j * CUB;
				yplayer = i * CUB;
				break;
				j++;
			}
			i++;
		}
	
	}
}
void  map2d()
{
	int x;
	float scale = 0.2;
	//setup();
	fov = 60 * (M_PI / 180);
	num_rays = width;
	//printf("%d %d", map_rows, map_clumns);
	for (int i = 0; i < map_rows; i++)
	{
		for (int j = 0; j < ft_strlen(map[i]); j++)
		{
				
			if (map[i][j] != ' ')
			{
					drawcub((i * CUB) * scale, (j * CUB) * scale, 0xffffff);

				if (map[i][j] == '1')
				{
					drawcub((i * CUB) * scale, (j * CUB) * scale, 0xFF0000);
				}
				// if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'E') && !found)
				// {
				// 		found = 1;
				// 		xplayer = j * CUB + CUB / 2;
				// 		yplayer = i * CUB + CUB / 2;
				// 		//c = map[i][j];
				// 		rotationangle = 0;
				// 	//pxl_ptr[xplayer * map_clumns + yplayer] = 0xffb703;
					
					
				// }
			}
			
			
		}
	}
	//pxl_ptr[xplayer * map_clumns + yplayer] = 0xffb703;
	//vision(0xffb703);
//	H_intersection(0xffb703);
	/*if (compt == 0 && c == 'N')
		vision_N(0xffb703);
	if (compt == 0 && c == 'S')
		vision_S(0xffb703);
	if (compt == 0 && c == 'W')
		vision_W(0xffb703);
	if (compt == 0 && c == 'E')
		vision_E(0xffb703);
	if (compt == 2)
		vision_N(0xffb703);
	if (compt == 1)
		vision_W(0xffb703);
	if (compt == 3)
		vision_S(0xffb703);
	if (compt == 4)
		vision_E(0xffb703);*/
	//my_mlx_pixel_put(xplayer, yplayer, 0xffb703, img_ptr);

	//mlx_put_image_to_window ( mlx_ptr, win_ptr, img_ptr, 0,  0);
}

int  keypressed(int key)
{
	//printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 124)
		turndirection = 1;
	if (key == 123)
		turndirection = -1;
	if (key == 13)
		walkdirection = 1;;
	if (key == 1)
		walkdirection = -1;
	/*if (key == 0)
		compt = 5;
	if (key == 2)
		compt = 6;*/
	render();
	return 0;
}

int  keyReleased(int key)
{
	//printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 124)
		turndirection = 0;
	if (key == 123)
		turndirection = 0;
	if (key == 13)
		walkdirection = 0;;
	if (key == 1)
		walkdirection = 0;
	/*if (key == 0)
		compt = 5;
	if (key == 2)
		compt = 6;*/
	//map2d();
	return 0;
}

int	draw_txtur(	int *tmp, int txt_width)
{

	//printf("abc\n");
	return tmp[(int)texturoffsetX + ((int)texturoffsetY * txt_width)];
}

void		render_3d(t_rays *rays)
{
	int i;
	int j;
	t_txt txt;
	int *tmp;
	void *img_txt;
	int me;

	
	img_txt = (char *)mlx_xpm_file_to_image(mlx_ptr, "./eagle.xpm", &txt.txt_width, &txt.txt_height);
	tmp = (int*)mlx_get_data_addr(img_txt, &me, &me, &me);
	i = -1;
	txt.txt_width = 64;
	txt.txt_height = 64;
	distanceprojplane = ((width / 2) / tan(FOV / 2));
	//printf("%d", txt.txt_width);
	while (++i < width)
	{
		perpdistance = rays[i].distance * cos(rays[i].rayAngle - rotationangle);
		projectwallheight = (CUB / perpdistance) * distanceprojplane;
		wallstripheight = (int)projectwallheight;
		walltoppixel = (height / 2) - (wallstripheight / 2);
		//printf(" to |%f \n", wallstripheight);
		walltoppixel = walltoppixel < 0 ? 0 : walltoppixel;
		wallbottompixel = (height / 2) + (wallstripheight / 2);
		wallbottompixel = wallbottompixel > height ? height : wallbottompixel;
		if (rays[i].wasHitVertical)
			texturoffsetX = (int)rays[i].wallHitY / CUB;
		else 
			texturoffsetX = (int)rays[i].wallHitX / CUB;
		j = -1;
		//printf("%f\n", texturoffsetX);
        while (++j < height)
        {
            if (j < walltoppixel)
                my_mlx_pixel_put(i, j, 0x7f7f7f, img_ptr);
            else if (j >= walltoppixel && j <= wallbottompixel)
            {
				distancefromtop = j + (wallstripheight / 2) - (height / 2);
				texturoffsetY = distancefromtop * ((float)txt.txt_height / wallstripheight);
				//printf("%f", texturoffsetY);
                my_mlx_pixel_put(i, j, draw_txtur(tmp, txt.txt_width), img_ptr);
            }
            else if (j > wallbottompixel)
                my_mlx_pixel_put(i, j, 0x7f7f7f, img_ptr);
		}
	}
}

void        square(int x, int y, float width, int color)
{
    int     i;
    int     j;

    i = -1;
    while (++i < width)
    {
        j = -1;
        while (++j < width)
        {
            my_mlx_pixel_put((x + j), (y + i), color, img_ptr);
        }
    }
}

void		render()
{
	//vision();
	//castAllRays();
	// for (int i = 0; i < map_clumns * CUB; i++) {
	// 	for (int j = 0; j < map_rows * CUB; j++) {
	// 		my_mlx_pixel_put(j, i, 0, img_ptr);
	// 	}
	// }
	int k;
	t_rays rays[width];
	mlx_clear_window(mlx_ptr, win_ptr);
	// pxl_ptr = (int *)mlx_get_data_addr(img_ptr, &k, &k, &k);

	//player_p();
	//printf("%f\n",rotationangle);
	vision();
	castAllRays(rays, 0);
	render_3d(rays);
	map2d();
	square(xplayer * 0.2, yplayer * 0.2, 10 * 0.2, 0xFF0000);
	castAllRays(rays, 1);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0,  0);
}
/*
int         moove()
{
	mlx_hook(win_ptr, 1, (2L<<2), keypressed, (void*)0);
	mlx_hook(win_ptr, 2, (2L<<2), keyReleased, (void*)0);
	render();
	return (0);
}*/

int cub3d()
{
	int k;

	setup();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "cub3d");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	render();
	//map2d();
	//mlx_loop_hook(mlx_ptr, moove, (void*)0);
	mlx_hook(win_ptr, 2, (2L<<2), keypressed, (void*)0);
	mlx_hook(win_ptr, 3, (2L<<2), keyReleased, (void*)0);
	mlx_loop(mlx_ptr);
	return 0;
}


int main(int argc, char *argv[])
{

	
	fd = open(argv[1], O_RDONLY); 
	map_file();
	cub3d();
	
}