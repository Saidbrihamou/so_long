SRCS	=	SRCS/main.c SRCS/get_next_line_bonus.c SRCS/get_next_line_utils_bonus.c SRCS/set_list_img.c \
			SRCS/move_plyare.c  SRCS/cheak_map.c SRCS/initializer_print_error.c SRCS/cheak_map_2.c SRCS/get_data_map_and_cheaksize.c \
			SRCS/ft_strdup.c SRCS/ft_strlen.c SRCS/ft_putstr_fd.c SRCS/ft_memcpy.c SRCS/ft_putnbr_fd.c SRCS/chaek_size_map.c

BONUS_SRCS = BONUS/main_bonus.c BONUS/get_next_line_bonus.c BONUS/get_next_line_utils_bonus.c BONUS/set_list_img_bonus.c \
		    BONUS/move_plyare_bonus.c  BONUS/cheak_map_bonus.c BONUS/initializer_print_error_bonus.c BONUS/cheak_map_2_bonus.c \
			BONUS/get_data_map_and_cheaksize_bonus.c BONUS/ft_strdup_bonus.c BONUS/ft_strlen_bonus.c BONUS/ft_putstr_fd_bonus.c \
			BONUS/ft_memcpy_bonus.c BONUS/ft_putnbr_fd_bonus.c BONUS/enemy_move_bonus.c BONUS/ft_itoa_bonus.c BONUS/main_cheak_bonus.c \
			BONUS/enemy_move_animition_bonus.c BONUS/insialise_and_get_direction_bonus.c BONUS/bfs_bonus.c BONUS/free_memory_bonus.c

BONUS_OBJ 	=	${BONUS_SRCS:.c=.o}
OBJS		=	${SRCS:.c=.o}
LINKS		= 	-lmlx -framework OpenGL -framework AppKit
FLAGS 		=	 -Wall -Wextra -Werror

NAME = so_long

all: $(NAME)

$(NAME): ${OBJS}
		cc ${OBJS} ${FLAGS} ${LINKS} -o ${NAME}

SRCS/%.o:SRCS/%.c SRCS/ft_so_long.h
		cc -c ${FLAGS} $< -o $@

BONUS/%.o:BONUS/%.c BONUS/ft_so_long_bonus.h 
		cc -c ${FLAGS} $< -o $@

clean:
	rm -rf ${OBJS} ${BONUS_OBJ}

fclean: clean
	rm -rf ${NAME}

bonus: ${BONUS_OBJ}
		cc ${BONUS_OBJ} ${FLAGS} ${LINKS} -o ${NAME}

re : fclean all