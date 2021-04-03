/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:22:14 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:29:10 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION IN PUSH_SWAP.H
*/

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <sys/types.h>
# include <limits.h>
# include <fcntl.h>

/*
** max size of int with sign - for show with option -v
*/

# define INTSIZE	11

/*
** parameters of pixel size
*/

# define MAC_BPP	4

/*
** window parameter
*/

# define WIDTH		1400
# define HEIGHT		800
# define VBRIM		20
# define HBRIM		40
# define ADD		40

/*
** colors of stack
*/

# define ACOL		0xFF0000
# define BCOL		0x00FFFF
# define BORD		0xFFFFFF

/*
** quit win for image by esc
*/

# define QUIT_KEY	53

/*
** struct for draw
** mlx_ptr - pointer for draw: init work
** mlx_win - pointer for window
** height - height of window
** width - width of window
** img_ptr - pointer to image
** adr - address of start of the memory for image
** bpp - bytes for pixel
** size_line - number of bytes used to store one line of the image in memory
** endian - endian: format of order
** color for pixel
*/

typedef struct		s_graf
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				height;
	int				width;
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
}					t_graf;

/*
** struct for stack A or B
** arr: array for keep int
** size: number of int
** id_index: array of int for keep ideal index of each int
** sort_par: index of insorting of stack - sum of delta of index
*/

typedef	struct		s_stack
{
	int				*arr;
	int				size;
	int				*id_index;
	int				sort_par;
}					t_stack;

/*
** struct for common parameters of stack
** shift: shift of stack A relativly of initial status
** debag: option for show sorting process in STDOUT
** onearg: flag for one command option used
** twoarg: flag for two command option used
** threearg: flag for three command option used
** fourarg: flag four three command option used
** color: color for debager
** fd: fd for using with option -f
** num_comm: for using with option -s - number of commands using
** draw: flag for visualisator on
** grow_x, grow_y: coeffs for visualise in grow scale
** size1, size2: flag for count sign for negative for stack a and b
** n, l: element of stack for print
** num_s: 1 - print change to stack a, 2 - print stack b,
** 0 - don't print in stack
*/

typedef struct		s_stack_m
{
	int				shift;
	int				debag;
	int				onearg;
	int				twoarg;
	int				threearg;
	int				fourarg;
	int				color;
	int				fd;
	int				num_comm;
	int				draw;
	int				grow_x;
	int				grow_y;
	int				size1;
	int				size2;
	int				n;
	int				l;
	int				num_s;
	t_stack			stack_a;
	t_stack			stack_b;
	t_graf			graf;
}					t_stack_m;

void				add_color(int color, int *arr, int i);
int					check_double(t_stack *stack);
void				clean_up_map(void **map, int height);
int					close_x(void *param);
int					count_height(char **str);
void				count_id_index(t_stack *stack, int size);
int					count_numbers(int argc, char **argv, t_stack_m *stack);
void				count_width_stack(t_stack_m *stack, int i);
int					fill_stack_a(int i, char **argv, int argc,\
					t_stack_m *stack);
int					fill_stack_a_str(char **num_arr, int height,\
					t_stack_m *stack);
int					found_id_index_and_draw(t_stack_m *stack);
int					ft_abs(int a);
int					ft_intlen(int nbr, uint8_t base);
int					ft_isnum(char *str);
void				ft_swap_int(int *a, int *b);
void				free_stacks(t_stack_m *stack);
void				image_pixel_put(t_stack_m *stack, int x, int y, int color);
int					init_draw(t_stack_m *stack);
int					init_i(t_stack_m *stack);
void				init_image_parameter(t_stack_m *stack);
void				init_index(t_stack *stack, int	size);
int					init_print(t_stack_m *stack, int n, int l, int num_s);
int					init_print_both(t_stack_m *stack, int n, int l);
int					init_stack(t_stack *stack);
int					key_press(int key, void *param);
int					make_stack(int argc, char **argv, t_stack_m *stack);
int					min_two_int(int a, int b);
void				num_of_commands(t_stack_m *stack, int argc, char **argv);
void				pa_command(t_stack_m *stack);
int					parse_arg_num(int i, int argc, char **argv);
int					parce_args(t_stack_m *stack, int argc, char **argv);
int					parce_string_arg_num(char **num_arr, int height);
void				parce_options_ch(char **argv, t_stack_m *stack);
void				parce_options_ch_1(char *str, t_stack_m *stack);
void				parce_options_ch_2(char *str1, char *str2,\
					t_stack_m *stack);
void				parce_option_ch_3(char *str1, char *str2, char *str3,\
					t_stack_m *stack);
void				pb_command(t_stack_m *stack);
void				print_both_stacks(t_stack_m *stack, int n, int l);
void				print_pa(t_stack_m *stack, int n, int m, int num_s);
void				print_pb(t_stack_m *stack, int n, int m, int num_s);
void				print_ra(t_stack_m *stack, int n, int m, int num_s);
void				print_rb(t_stack_m *stack, int n, int m, int num_s);
void				print_rr(t_stack_m *stack, int n, int m, int num_s);
void				print_rra(t_stack_m *stack, int n, int m, int num_s);
void				print_rrb(t_stack_m *stack, int n, int m, int num_s);
void				print_rrr(t_stack_m *stack, int n, int m, int num_s);
void				print_sa(t_stack_m *stack, int n, int m, int num_s);
void				print_sb(t_stack_m *stack, int n, int m, int num_s);
void				print_space(int size);
void				print_ss(t_stack_m *stack, int n, int m, int num_s);
void				print_stack_a(t_stack_m *stack, int i, int k);
void				print_stacks(t_stack_m *stack, int n, int m, int num_s);
void				print_start(t_stack_m *stack, int n, int m, int num_s);
void				print_usage(void);
void				ra_command(t_stack_m *stack);
void				rb_command(t_stack_m *stack);
int					read_command(t_stack_m *stack);
int					refresh_image(t_stack_m *stack);
void				rr_command(t_stack_m *stack);
void				rra_command(t_stack_m *stack);
void				rrb_command(t_stack_m *stack);
void				rrr_command(t_stack_m *stack);
void				sa_command(t_stack_m *stack);
void				sb_command(t_stack_m *stack);
char				**split_string(char *str, int *height);
void				ss_command(t_stack_m *stack);
void				stack_is_sorted(t_stack_m *stack);
void				usage_with_exit(void);
int					visualize_sort(t_stack_m *stack);
void				work_with_options(t_stack_m *stack, char **argv, int argc);

#endif
