# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malannys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 01:43:36 by malannys          #+#    #+#              #
#    Updated: 2019/09/04 21:11:38 by malannys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

INC := ./inc/
SRC := ft_isdigit.c ft_lstmap.c ft_memdel.c ft_putnbr.c ft_strjoin.c ft_strncpy.c ft_strsub.c \
	ft_isprint.c ft_lstnew.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c ft_strlcat.c ft_strlen.c ft_strnequ.c ft_strtrim.c \
	ft_atoi.c ft_itoa.c ft_memalloc.c ft_memset.c ft_putstr.c ft_strdel.c ft_strnew.c ft_tolower.c \
	ft_bzero.c ft_lstadd.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c ft_strdup.c ft_strmap.c ft_strnstr.c \
	ft_toupper.c ft_isalnum.c ft_lstdel.c ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_strequ.c ft_strmapi.c \
	ft_strrchr.c ft_isalpha.c ft_lstdelone.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_striter.c ft_strncat.c \
	ft_strsplit.c ft_isascii.c ft_lstiter.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c ft_strncmp.c \
	ft_strstr.c ft_del.c ft_lst_back.c ft_lst_pop_back.c ft_lst_pop_front.c ft_lst_push_back.c ft_lstsize.c \
	ft_pow.c ft_sqrt.c ft_realloc.c ft_quick_sort.c ft_strcmp.c
OBJ := $(SRC:.c=.o)

CFLAGS := -Wall -Wextra -Werror
CC := gcc

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	ar rc $@ $(OBJ)
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
