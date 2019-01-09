# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 20:46:23 by ksnow-be          #+#    #+#              #
#    Updated: 2018/12/03 18:39:03 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_bzero.c \
	   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
	   ft_strcmp.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
	   ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strcpy.c ft_strrchr.c \
	   ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c \
	   ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_strsplit.c ft_itoa.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstiter.c ft_lstadd.c ft_lstnew.c ft_double_oper.c ft_spacer.c \
	   ft_word_count.c ft_word_filler.c ft_del.c ft_lstmap.c

OBJ = $(SRCS:.c=.o)

FLAGS = gcc -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o: %.c
		@$(FLAGS) -c $< -o $@
		@echo -n =

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
