# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abykov <abykov@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 15:51:41 by abykov            #+#    #+#              #
#    Updated: 2017/02/12 17:54:42 by abykov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_PATH = .
LIB_PATH = ./libft
INC_PATH = .
OBJ_PATH = .
OBJLIB_PATH = ./libft

SRC_NAME =	data_func.c \
			ft_printf.c \
			ft_printf_c.c \
			ft_printf_d.c \
			ft_printf_ou.c \
			ft_printf_x.c \
			ft_printf_p.c \
			ft_printf_s.c \
			select_func.c \
			ft_itoa_base.c

LIB_NAME = 	ft_strchr.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strnstr.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)
	
$(NAME): $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
norme:
	@norminette $(SRC) $(LIB) $(INC)
