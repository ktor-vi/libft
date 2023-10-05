# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktorvi <ktorvi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 07:03:04 by ktorvi            #+#    #+#              #
#    Updated: 2023/10/03 14:11:45 by ktorvi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c  \
	  ft_memset.c  \
	  ft_bzero.c   \
	  ft_memcpy.c  \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c  \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_memchr.c  \
		ft_memcmp.c  \
		ft_strnstr.c \
		ft_atoi.c    \



INC = libft.h

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
