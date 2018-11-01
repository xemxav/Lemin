# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 15:01:29 by xmoreau      #+#   ##    ##    #+#        #
#    Updated: 2018/06/07 13:53:11 by xmoreau     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: clean fclean re all

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

HEADER = libft.h

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strrev.c \
		ft_intcount.c \
		ft_triabulles.c \
		get_next_line.c \
		fd_printf.c \
		flag_parsing2.c \
		ft_printf.c \
		itoa_base_s.c \
		itoa_base_u.c \
		make_flags.c \
		make_s_c.c \
		precision.c \
		run_big_c.c \
		run_big_s.c \
		start_processing.c \
		processing.c \
		struct_management.c \
		trees.c \
		width_for_chr.c \
		width.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) -I $(HEADER) -o $@ -c $<

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) has been created"
clean :
	@rm -f $(OBJ)
	@echo "all the objects have been deleted"
fclean : clean
	@rm -f $(NAME)
	@echo "$(NAME) has been deleted"

re : fclean all
	@echo "$(NAME) is fresh new"
