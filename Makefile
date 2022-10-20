UNAME = $(shell uname -s)

NAME = fract_ol

CC	=	cc

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

ifeq ($(UNAME), Darwin)
	CFLAGS = -Wall -Wextra -Werror
	FLAGS = -lmlx -framework OpenGL -framework AppKit
else
	CFLAGS = -Wall -Wextra -Werror -D LINUX -Imlx_linux
	FLAGS = -Lmlx_linux minilibx-linux/libmlx_Linux.a -L/usr/lib  -lXext -lX11 -lm -lz 
endif

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
