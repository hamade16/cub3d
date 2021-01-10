NAME = cub3d.a

SRC = main.c ft_atoi.c get_next_line.c get_next_line_utils.c map_utils.c ft_putstr_fd.c ft_split.c ft_strchr.c check_error.c visionR.c ft_putchar_fd.c rays.c drawing_functions.c

OBJECT = main.o ft_atoi.o get_next_line.o get_next_line_utils.o map_utils.o ft_putstr_fd.o ft_split.o ft_strchr.o check_error.o visionR.o ft_putchar_fd.o rays.o drawing_functions.o

all : $(NAME)

$(NAME):
		@cc  -g -I /Users/houbeid/Desktop/githubcub3d $(SRC) -D BUFFER_SIZE=1 -L /Users/houbeid/Desktop/githubcub3d -lmlx -framework OpenGL -framework AppKit -lz -g3 -o  Cub3D

clean:
	@rm -rf $(OBJECT)
fclean: clean
	@rm -rf $(NAME)
re : fclean all
