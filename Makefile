NAME = cub3d.a

SRC = main.c ft_atoi.c get_next_line.c get_next_line_utils.c map_utils.c ft_putstr_fd.c ft_split.c ft_strchr.c  visionR.c ft_putchar_fd.c rays.c drawing_functions.c ft_setup.c ft_check_error.c\
ft_setup_util.c ft_isdigit.c ft_setmap.c ft_strlen.c ft_strdup.c ft_strtrim.c ft_toupper.c ft_tolower.c ft_utils.c ft_strncmp.c texture.c

OBJECT = main.o ft_atoi.o get_next_line.o get_next_line_utils.o map_utils.o ft_putstr_fd.o ft_split.o ft_strchr.o visionR.o ft_putchar_fd.o rays.o drawing_functions.o ft_setup.o ft_check_error.o\
ft_setup_util.o ft_isdigit.o ft_setmap.o ft_strlen.o ft_strdup.o ft_strtrim.o ft_toupper.o ft_tolower.o ft_utils.o ft_strncmp.o texture.o

all : $(NAME)

$(NAME):
		@cc  -g -I /Users/houbeid/Desktop/githubcub3d $(SRC)  -g -fsanitize=address -D BUFFER_SIZE=1 -L /Users/houbeid/Desktop/githubcub3d -lmlx -framework OpenGL -framework AppKit -lz -g3 -o  Cub3D

clean:
	@rm -rf $(OBJECT)
fclean: clean
	@rm -rf $(NAME)
re : fclean all
