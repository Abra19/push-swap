NAME	= push_swap
CHECK 	= checker

CC	= gcc
FLAGS	=  -Wall -Wextra -Werror -g

INCLUDE = -I$(HEADDIR) -I$(LFTHEAD) -I$(PFTHEAD)
INCLUDE_CHECK = -I$(HEADDIR) -I$(LFTHEAD) -I$(PFTHEAD) -I$(MLXHEAD)

LFTLIB	= -lft -L$(LFTDIR)
LIBFT	= $(LFTDIR)libft.a
LFTDIR	= ./libft/
LFTHEAD = $(LFTDIR)includes/

PFTLIB	= -lft -L$(PFTDIR)
PFT	= $(PFTDIR)libftprintf.a
PFTDIR	= ./libftprintf/
PFTHEAD = $(PFTDIR)includes/

MLXLIB	= -lmlx -L$(MLXDIR) -framework OpenGL -framework AppKit
MLX	= $(MLXDIR)libmlx.a
MLXDIR	= ./minilibx/
MLXHEAD = $(MLXDIR)

HEADLST = push_swap.h
HEADDIR = ./includes/
HEADERS = $(addprefix $(HEADDIR), $(HEADLST))

HEADLST_CHECK = checker.h
HEADERS_CHECK = $(addprefix $(HEADDIR), $(HEADLST_CHECK))

SRCLST = main.c parce.c tools.c alloc_and_clean.c command.c sorter.c\
		max_subsequence.c command_2.c init.c parce_2.c tools_2.c\
		combination.c print_command.c print_command_2.c print_command_3.c\
		print_command_4.c sorter_2.c sorter_3.c sorter_4.c sorter_5.c\
		sorter_6.c
SRCDIR = ./srcs/push_swap/
SRCS = $(addprefix $(SRCDIR), $(SRCLST))

SRCLST_CHECK = main.c alloc.c command.c parce.c command_2.c command_3.c\
			print_command.c print_stacks.c tools.c visualize.c parce_options.c\
			parce_options_2.c read_command.c parce_arg.c init.c parce_2.c\
			print_command_2.c print_command_3.c print_stacks_2.c vizualize_2.c
SRCDIR_CHECK = ./srcs/checker/
SRCS_CHECK = $(addprefix $(SRCDIR_CHECK), $(SRCLST_CHECK))

OBJDIR = ./obj/push_swap/
OBJLST = $(patsubst %.c, %.o, $(SRCLST))
OBJECTS	= $(addprefix $(OBJDIR), $(OBJLST))

OBJDIR_CHECK = ./obj/checker/
OBJLST_CHECK = $(patsubst %.c, %.o, $(SRCLST_CHECK))
OBJECTS_CHECK	= $(addprefix $(OBJDIR_CHECK), $(OBJLST_CHECK))

.PHONY: all clean fclean re

all: $(NAME) $(CHECK)

$(NAME): $(LIBFT) $(PFT) $(OBJDIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(LFTLIB) $(LIBFT) $(PFTLIB) $(PFT) $(INCLUDE) $(OBJECTS) -o $(NAME)
	@echo "executable push_swap maked"

$(CHECK): $(LIBFT) $(PFT) $(MLX) $(OBJDIR_CHECK) $(OBJECTS_CHECK)
	@$(CC) $(FLAGS) $(LFTLIB) $(LIBFT) $(PFTLIB) $(PFT) $(MLXLIB) $(MLX) $(INCLUDE_CHECK) $(OBJECTS_CHECK) -o $(CHECK)
	@echo "executable checker maked"
	
$(OBJDIR):
	@mkdir -p ./obj
	@mkdir -p $(OBJDIR)
	@echo "object dir push_swap created"

$(OBJDIR_CHECK):
	@mkdir -p $(OBJDIR_CHECK)
	@echo "object dir checker created"

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDE) $< -o $@
	@echo "obj for push_swap"

$(OBJDIR_CHECK)%.o : $(SRCDIR_CHECK)%.c $(HEADERS_CHECK)
	@$(CC) $(FLAGS) -c $(INCLUDE_CHECK) $< -o $@
	@echo "obj for checker"

$(LIBFT): $(LFTHEAD)
	@make -C $(LFTDIR)
	@echo "libft maked"

$(PFT): $(PFTHEAD)
	@make -C $(PFTDIR)
	@echo "libftprintf maked"

$(MLX): $(MLXHEAD)
	@make -C $(MLXDIR)
	@echo "mlx maked"

clean:
	@$(MAKE) -C $(LFTDIR) clean
	@$(MAKE) -C $(PFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf ./obj
	@rm -rf $(OBJDIR)
	@echo "clean maked"
	
fclean: clean
	@rm -f $(PFT)
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@rm -f $(CHECK)
	@rm -f $(NAME)
	@echo "fclean maked"

re: fclean all
