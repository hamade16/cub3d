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

	r = 0;
	i = 0;
	j = 0;
	mp = ft_strdup("\0");
	map_clumns = 0;
	map_rows = 1;
	a = 0;
	compt = 0;
	
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
	/*pfree = mp;
	mp = ft_strjoin(mp, "\n");
	free(pfree);*/
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
			/*pfree = mp;
			mp = ft_strjoin(mp, "\n");
			free(pfree);*/
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
			//map_clumns = ft_strlen(line);
			/*pfree = mp;
			mp = ft_strjoin(mp, "\n");
			free(pfree);*/
		}
		/*else
		{	r = ft_strlen(line);
			while(r < map_clumns)
			{
				mp[r] = ' ';
				r++;
			}
		}*/
		map_rows += 1;
		if (is_empty(line))
			ft_err("hello world\n");
	}
	/*pfree = mp;
	mp = ft_strjoin(mp, line);
	free(pfree);
	if (map_clumns < ft_strlen(line))
		map_clumns = ft_strlen(line);
	map_rows += 1;
	if (is_empty(line))
			ft_err("hello world\n");
	pfree = mp;
	mp = ft_strjoin(mp, "\n");
	free(pfree);*/
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
	while (map[r])
	{
		printf("%s\n", map[r]);
		r++;
	}
	printf("%d\n", map_rows);
	printf("%d\n", map_clumns);
}

void  drawcub(int x, int y, int color)
{
	for (int i = x; i < x + cub; i++)
	{
		for (int j = y; j < y + cub; j++)
		{
			pxl_ptr[i * (cub * map_clumns) + j] = color;
		}
	}
}

int found = 0;
void  map2d()
{
	fov = 60 * (M_PI / 180);
	num_rays = map_clumns;
	//printf("%d %d", map_rows, map_clumns);
	for (int i = 0; i < map_rows; i++)
	{
		for (int j = 0; j < ft_strlen(map[i]); j++)
		{
				
			if (map[i][j] != ' ')
			{
					drawcub((i * cub), (j * cub), 0xffffff);

				if (map[i][j] == '1')
				{
					drawcub((i * cub), (j * cub), 0xFF0000);
				}
				if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'E') && !found)
				{
						found = 1;
						xplayer = j * cub;
						yplayer = i * cub;
						c = map[i][j];
						rotationangle = M_PI / 2;
					//pxl_ptr[xplayer * map_clumns + yplayer] = 0xffb703;
					
					
				}
			}
			
			
		}
	}
	//pxl_ptr[xplayer * map_clumns + yplayer] = 0xffb703;
	vision(0xffb703);
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
	mlx_put_image_to_window ( mlx_ptr, win_ptr, img_ptr, 0,  0);
}

int  keypressed(int key)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 124)
		turndirection = -1;
	if (key == 123)
		turndirection = 1;
	if (key == 13)
		walkdirection = 1;;
	if (key == 1)
		walkdirection = -1;
	/*if (key == 0)
		compt = 5;
	if (key == 2)
		compt = 6;*/
	map2d();
	return 0;
}

int  keyReleased(int key)
{
	printf("%d\n", key);
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

int cub3d()
{
	int k;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "cub3d");
	img_ptr = mlx_new_image(mlx_ptr, (cub * map_clumns), (cub * map_rows));
	pxl_ptr = (int *)mlx_get_data_addr(img_ptr, &k, &k, &k);
	map2d();
	mlx_hook(win_ptr ,2, (2L<<2), keypressed, (void*)0);
	mlx_hook(win_ptr ,3, (2L<<2), keyReleased, (void*)0);
	mlx_loop(mlx_ptr);
	return 0;
}


int main(int argc, char *argv[])
{

	
	fd = open(argv[1], O_RDONLY); 
	map_file();
	cub3d();
	
}