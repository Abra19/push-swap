#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlaure <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 18:05:26 by dlaure            #+#    #+#              #
#    Updated: 2019/10/14 16:04:55 by dlaure           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDE = -I$(HEADDIR)

HEADLST = libft.h get_next_line.h
HEADDIR = ./includes/
HEADERS = $(addprefix $(HEADDIR), $(HEADLST))

SRCDIR = ./
SRCLST = ft_atoi.c ft_fibonacci.c ft_find_next_prime.c\
	ft_is_power_of_2.c ft_is_prime.c ft_is_sqrt.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c\
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c\
	ft_strclr.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
	ft_strlcat.c ft_strmap.c ft_strmapi.c ft_strncat.c\
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c\
	ft_strsplit.c ft_strstr.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	get_next_line.c
SRC = $(addprefix $(SRCDIR), $(SRCLST))

OBJDIR = obj/
OBJLST = $(patsubst %.c, %.o, $(SRCLST))
OBJECTS	= $(addprefix $(OBJDIR), $(OBJLST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "libft created"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

