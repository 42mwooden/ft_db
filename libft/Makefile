# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/25 19:36:52 by mwooden           #+#    #+#              #
#    Updated: 2017/01/07 23:53:15 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = srcs


FILENAMES =\
		   ft_putchar.c\
		   ft_strlen.c\
		   ft_putnbr.c\
		   ft_putstr.c\
		   ft_strcat.c\
		   ft_strncat.c\
		   ft_strcpy.c\
		   ft_strcmp.c\
		   ft_strncpy.c\
		   ft_strncmp.c\
		   ft_strstr.c\
		   ft_atoi.c\
		   ft_strnstr.c\
		   ft_isalpha.c\
		   ft_isdigit.c\
		   ft_isalnum.c\
		   ft_isascii.c\
		   ft_isprint.c\
		   ft_strchr.c\
		   ft_strrchr.c\
		   ft_strlcat.c\
		   ft_tolower.c\
		   ft_toupper.c\
		   ft_putendl.c\
		   ft_itoa.c\
		   ft_putnbr_fd.c\
		   ft_putstr_fd.c\
		   ft_putendl_fd.c\
		   ft_putchar_fd.c\
		   ft_strsplit.c\
		   ft_strtrim.c\
		   ft_strjoin.c\
		   ft_strsub.c\
		   ft_strequ.c\
		   ft_strnequ.c\
		   ft_strmap.c\
		   ft_strmapi.c\
		   ft_striter.c\
		   ft_striteri.c\
		   ft_strclr.c\
		   ft_strdel.c\
		   ft_strnew.c\
		   ft_memalloc.c\
		   ft_memset.c\
		   ft_memdel.c\
		   ft_bzero.c\
		   ft_memcpy.c\
		   ft_memccpy.c\
		   ft_memmove.c\
		   ft_memchr.c\
		   ft_memcmp.c\
		   ft_strdup.c\
		   ft_lstnew.c\
		   ft_lstdelone.c\
		   ft_lstdel.c\
		   ft_lstadd.c\
		   ft_lstiter.c\
		   ft_lstmap.c\
		   ft_isprime.c\
		   ft_primefact.c\
		   ft_lstrev.c\
		   ft_power.c\
		   ft_sqrt.c\
		   ft_escape.c\
		   my_realloc.c\
		   get_next_line.c

INCLUDES = -I libft.h

NAME = libft.a

SRCS = $(FILENAMES)
OBJS = $(FILENAMES:.c=.o)

CC = gcc
AR = ar

CFLAGS ?= -Wall -Wextra -Werror
CFLAGS += $(INCLUDES)

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $@ $^
	ranlib $@

./%.o: ./%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
