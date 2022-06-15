# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 15:00:07 by taitomer          #+#    #+#              #
#    Updated: 2022/05/23 10:37:50 by taitomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = make -C ./libft/

LIBFTA = ./libft/libft.a

SRCS = draw_help.c draw.c helpers.c \
		key_stuff.c main.c read_file.c

OBJ = draw_help.o draw.o helpers.o \
		key_stuff.o main.o read_file.o

all: $(NAME)

$(NAME):
	@$(LIBFT)
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFTA)

clean:
	@echo "..."
	@rm -f $(OBJ)
	@$(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(LIBFT) fclean

re: fclean all
