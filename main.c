#include "cub3d.h"
#include "mlx.h"

void  drawcub(float x, float y, int width, int height, int color)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			my_mlx_pixel_put(j, i, color, img_ptr);
		}
	}
}

int found = 0;
/*void	player_p()
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
}*/

void  map2d()
{
	int x;
	float scale = 0.2;
	//setup();
	fov = 60 * (M_PI / 180);
	num_rays = width;
	for (int i = 0; i < map_rows; i++)
	{
		for (int j = 0; j < map_clumns; j++)
		{
			// write(1, &map[i][j], 1);
			// if (map[i][j] != ' ')
			// {
				if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '2')
					drawcub((i * CUB) * scale, (j * CUB) * scale, CUB * scale, CUB * scale, 0xffffff);
				else if (map[i][j] == '1')
					drawcub((i * CUB) * scale, (j * CUB) * scale, CUB * scale, CUB * scale, 0xFF0000);
				else if (map[i][j] == '2')
					drawcub((i * CUB) * scale, (j * CUB) * scale, CUB * scale, CUB * scale, 0xFF00FF);
			// }
			
			
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

int wall_to_texture(int j, int i)
{
	int y;
	y = j + (wallstripheight / 2) - (height /2);
	return (y * (CUB/ wallstripheight));
}
void		render_3d()
{
	int i;
	int j;
	t_txt txt;
	void *img_txt;
	int me;
	int *textur;
	int texture_start;
	
	
	i = 0;
	txt.txt_width = 64;
	txt.txt_height = 64;
	distanceprojplane = ((width / 2) / tan(FOV / 2));
	while (i < width)
	{
		textur = fetch_texture(i);
		perpdistance = rays[i].distance * cos(rays[i].rayAngle - rotationangle);
		projectwallheight = (CUB / perpdistance) * distanceprojplane;
		wallstripheight = (int)projectwallheight;
		walltoppixel = (height / 2) - (wallstripheight / 2);
		walltoppixel = walltoppixel < 0 ? 0 : walltoppixel;
		wallbottompixel = (height / 2) + (wallstripheight / 2);
		wallbottompixel = wallbottompixel > height ? height : wallbottompixel;
		
		if (rays[i].wasHitVertical)
		{
			texture_start = fmod(rays[i].wallHitY ,CUB);
			//ft_putchar('a');
		}
		else
			texture_start = fmod(rays[i].wallHitX,CUB);
		j = -1;

        while (++j < height)
        {
				int n = (wall_to_texture(j,i) * CUB) + texture_start;
				if (n >= 4096)
					n = 4095;
				if (n < 0)
					n = 0;
            if (j < walltoppixel)
                my_mlx_pixel_put(i, j, 0x7f7f7f, img_ptr);
            else if (j >= walltoppixel && j <= wallbottompixel)
            {

                my_mlx_pixel_put(i, j, textur[n] , img_ptr);
            }
            else if (j > wallbottompixel)
                my_mlx_pixel_put(i, j, 0x7f7f7f, img_ptr);
		}
		i++;
	}
}

void		render()
{
	
	mlx_clear_window(mlx_ptr, win_ptr);
	vision();
	castAllRays(0);
	render_3d(rays);
	calcul_sprite();
	map2d();
	castAllRays(1);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0,  0);
}

int cub3d()
{
	int k;

	setup2();
	
	win_ptr = mlx_new_window(mlx_ptr, width, height, "cub3d");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	render();
	mlx_hook(win_ptr, 2, (2L<<2), keypressed, (void*)0);
	mlx_hook(win_ptr, 3, (2L<<2), keyReleased, (void*)0);
	mlx_loop(mlx_ptr);
	return 0;
}


int main(int argc, char *argv[])
{

	int i;

	i = 0;
	mlx_ptr = mlx_init();
	setup(argv[1]);
	cub3d();
	
}