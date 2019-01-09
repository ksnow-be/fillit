# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 09:09:09 by ksnow-be          #+#    #+#              #
#    Updated: 2019/01/09 09:26:22 by ksnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

READY = \033[36m
NORM = \033[0m
RED = \033[31m
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC = fillit.h

SRC_NAME = main.c addit.c cut.c check.c algo.c help.c node.c

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft
		@echo "\n$(READY)\t\tusage: ./fillit [filename]$(NORM)"
		@echo ===============================================================


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CC_FLAGS) -I $(INC) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(RED)./fillit removed$(NORM)"

re: fclean all
