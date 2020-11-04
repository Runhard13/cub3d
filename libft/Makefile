# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: null <null@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 02:12:15 by null              #+#    #+#              #
#    Updated: 2020/11/04 12:55:00 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

SRCS=	ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strncmp.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_substr.c \
ft_strjoin.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_itoa.c \
ft_split.c \
ft_strmapi.c \
ft_strtrim.c

SRCS_B=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c

OBJECTS=$(SRCS:.c=.o)

OBJECTS_B=$(SRCS_B:.c=.o)

INCLUDES=./

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_B)
	ar rc $(NAME) $(OBJECTS_B)
	ranlib $(NAME)
