# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/06 17:04:55 by xmoreau      #+#   ##    ##    #+#        #
#    Updated: 2018/08/16 17:48:52 by xmoreau     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = lem-in
PATH_OBJ = ./obj/
PATH_SRC = ./src/
PATH_INC = ./includes/

#******************************************************************************#
#                                  LEM-IN                                      #
#******************************************************************************#

FILES = main check_line recording is_correct_line free_n_exit record_tube bfs \
find_important get_paths record_path move_ants
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o , $(FILES)))
SRC = $(addprefix $(PATH_SRC), $(addsuffix .c , $(FILES)))

#******************************************************************************#
#                                  LIBFT                                       #
#******************************************************************************#

PATH_LIB = ./libft/
PATH_INC_LIB = ./libft/
NAME_LIB = ft
INC_LIB = -L $(PATH_LIB) -l $(NAME_LIB)

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(NAME)

clean:
	@printf "\n\033[1m SUPPRESSION DES OBJETS\033[0m\n"
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_LIB)

fclean: clean
	@printf "\n\033[1mSUPPRESSION DE $(NAME)\033[0m\n"
	@rm -rf $(NAME)
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_LIB)

re: fclean all

#******************************************************************************#
#                                  Compilation                                 #
#******************************************************************************#

$(NAME): $(PATH_OBJ) $(OBJ)
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(OBJ) -I $(PATH_INC) $(INC_LIB) -o $(NAME)
	@echo "$(NAME) has been compiled"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -I $(PATH_INC) -I $(PATH_INC_LIB) -c $< -o $@

$(PATH_OBJ):
	@mkdir $(PATH_OBJ)
