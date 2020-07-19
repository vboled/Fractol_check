

#GCC = gcc -Wall -Wextra -Werror -g -MMD

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

GCC = gcc -Wall -Wextra -Werror
NAME = fractol
SRCS = main.c \
		struct_work.c \
		window_work.c \
		image_work.c \
		fractol.c \
		fractol2.c \
		conversation.c \
		conversation2.c \
		line.c \
		color.c \
		color1.c

HEAD = -I$(INCDIR)

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libs/libft/libft.a  libs/minilibx/libmlx.a
	LIBMAKE := libs/minilibx
	LIB :=  -L libs/libft -lft -L libs/minilibx -lmlx_Linux -lXext -lX11 -lm
	HEAD += -I./libs/minilibx/
	SRCS += window_work_lin.c
endif
ifeq ($(detected_OS),Darwin) 
	MAKES = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
	LIBMAKE := libs/minilibx_macos
	LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
	HEAD += -I./libs/minilibx_macos/
	SRCS += window_work_mac.c
endif

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS = $(addprefix $(OBJDIR), $(SRCS:.c=.d))

.PHONY: clean fclean re
all: $(NAME) 

$(OBJDIR)%.o: $(SRCDIR)%.c 
	$(GCC) -MD -o $@ -c $(HEAD) $<

$(MAKES):
	make -C  libs/libft
	make -sC  $(LIBMAKE)

-include $(DEPENDS)

$(NAME): $(MAKES) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(DEPENDS)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean
	make -C $(LIBMAKE) clean

re: fclean all
