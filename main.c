#include "cub3d.h"
#include "mlx.h"

void  drawcub(float x, float y, int color)
{
	for (int i = x; i < x + CUB; i++)
	{
		for (int j = y; j < y + CUB; j++)
		{
			my_mlx_pixel_put(j, i, color, img_ptr);
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
			}
			
			
		}
	}
}

int  keypressed(int key)
{
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
	render();
	return 0;
}

int  keyReleased(int key)
{
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

	
	img_txt = (char *)mlx_xpm_file_to_image(mlx_ptr, "./floor_1.xpm", &txt.txt_width, &txt.txt_height);
	tmp = (int*)mlx_get_data_addr(img_txt, &me, &me, &me);
	i = -1;
	txt.txt_width = 64;
	txt.txt_height = 64;
	distanceprojplane = ((width / 2) / tan(FOV / 2));
	while (++i < width)
	{
		perpdistance = rays[i].distance * cos(rays[i].rayAngle - rotationangle);
		projectwallheight = (CUB / perpdistance) * distanceprojplane;
		wallstripheight = (int)projectwallheight;
		walltoppixel = (height / 2) - (wallstripheight / 2);
		walltoppixel = walltoppixel < 0 ? 0 : walltoppixel;
		wallbottompixel = (height / 2) + (wallstripheight / 2);
		wallbottompixel = wallbottompixel > height ? height : wallbottompixel;
		if (rays[i].wasHitVertical)
			texturoffsetX = (int)rays[i].wallHitY / CUB;
		else 
			texturoffsetX = (int)rays[i].wallHitX / CUB;
		j = -1;
        while (++j < height)
        {
            if (j < walltoppixel)
                my_mlx_pixel_put(i, j, 0x7f7f7f, img_ptr);
            else if (j >= walltoppixel && j <= wallbottompixel)
            {
				distancefromtop = j + (wallstripheight / 2) - (height / 2);
				texturoffsetY = distancefromtop * ((float)txt.txt_height / wallstripheight);
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
	t_rays rays[width];
	mlx_clear_window(mlx_ptr, win_ptr);
	//player_p();
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

	setup2();
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