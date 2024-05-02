NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
SRC = ../source_file/so_long.c ../source_file/map.c get_next_line.c utils.c
OBJ = *.o

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(MLXFLAGS) -o $(NAME)

$(OBJ): $(SRC)
	cc	$(FLAGS) -c $(SRC)

clean: $(OBJ)
	@rm -rf $(OBJ)
fclean:	clean
	@rm -rf $(NAME)
re: fclean all

.FHONY: all clean fclean re