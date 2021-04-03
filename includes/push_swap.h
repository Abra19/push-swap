/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:22:14 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/24 21:00:38 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** we have 2 stacks named a and b
** start: a contains a random number of either positive or negative numbers
** without any duplicates; b is empty
** goal is to sort this numbers in ascending order into stack a
** using authorized operation
** sa: swap the first 2 elements at the top of stack a
** sb: swap the first 2 elements at the top of stack b
** ss: sa and sb at the same time
** sa, sb: do nothing if there is only one or no elements
** pa: take the first element at the top of b and put it at the top of a
** pa: do nothing if b is empty
** pb: take the first element at the top of a and put it at the top of b
** pb: do nothing if a is empty
** ra: shift up all elements of stack a by 1: first element becomes
** the last one. Do nothing if there is only one or no elements
** rb: shift up all elements of stack b by 1: first element becomes
** the last one. Do nothing if there is only one or no elements
** rr: ra and rb at the same time
** rra: shift down all elements of stack a by 1: last element
** becomes the first one. Do nothing if there is only one or no elements
** rrb: shift down all elements of stack b by 1: last element
** becomes the first one. Do nothing if there is only one or no elements
** rrr: rra and rrb at the same time
**  push_swap programm receive as an argument the stack of integers
** first argument should be at the top of the stack
** program must display the smallest list of instructions possible to sort
** the stack a, the smallest number being at the top
** instructions must be separated by a ’\n’ and nothing else
** checker program check if the list of instructions generate
** with the program push_swap is actually sorting the stack properly
** checker get as an argument the stack of integers
** first argument -  at the top of the stack
** if no argument is given checker stops and displays nothing
** checker will then wait and read instructions on the standard input
** each instruction will be followed by ’\n’
** once all the instructions have been read (after ctrl+D), checker will
** execute them on the stack received as an argument
** if after executing those instructions, stack a is actually sorted
** and b is empty - checker display "OK" followed by a ’\n’ on STDOUT
** in other case, checker must display "KO" followed by a ’\n’ on STDOUT
** in both programm in case of error - display Error followed by a ’\n’
** n the STDERR.
** example of errors: some arguments are not integers, some arguments are
** bigger than an integer, there are duplicates, an instruction don’t exist
** or incorrectly formatted
**
** BONUSES
**
** PUSH SWAP
** option -f = argv[1] or argv[2] - write instructions to file
** option -help= argv[1] - show usage
** option -s = argv[1] or argv[2] - write number of instructions - STDOUT
**
** CHECKER
** option -s any place from argv[1] - argv[4], don't used with -m
** - write number of instructions - STDOUT
** option -v = only argv[1] (with -c, -f, -s or alone)
** display the stack’s status after each operation
** option -c = argv[2] (only with -v)
** show last operation in colour
** option -f any place from argv[1] - argv[4]
** - read instructions from file
** option -help - show usage
** option -m = argv[1]: graphic vizualizer (only with -f or alone)
** visualize if number of int:
** < WIDTH - 2 * VBRIM - ADD, HEIGHT - 2 * HBRIM - ADD
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <limits.h>
# include <fcntl.h>

/*
** max size of int with sign - for show with option -v
*/

# define INTSIZE	11

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
	int				*subarray;
	int				size;
	int				subsize;
	int				subgrow;
	int				min_ind;
	int				head;
	int				bottom;
	int				*transpos;
	int				*id_index;
	int				sort_par;
}					t_stack;

/*
** struct for common parameters of stack
** sort_par: index of insorting of stack - sum of delta of index
** and id index of each int
** shift: shift of stack A relativly of initial status
** debag: option for show sorting process in STDOUT
** onearg: flag for one command option used
** twoarg: flag for two command option used
** fd: fd for using with option -f
** num_comm: for using with option -s - number of commands using
** grow_x, grow_y: coeffs for visualise in grow scale
*/

typedef struct		s_stack_m
{
	int				sort_par;
	int				shift;
	int				onearg;
	int				twoarg;
	int				fd;
	int				num_comm;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				spec_mode;
	int				combination;
	int				comb_1;
	int				comb_2;
	int				comb_3;
	t_stack			stack_a;
	t_stack			stack_b;
}					t_stack_m;

int					check_double(t_stack *stack);
void				clean_up_map(void **map, int height);
void				combination(t_stack_m *stack);
int					count_height(char **str);
void				count_id_index(t_stack *stack, int size);
int					count_numbers(int argc, char **argv, t_stack_m *stack);
int					*create_intarr(unsigned size);
int					fill_stack_a(int i, char **argv, int argc,\
					t_stack_m *stack);
int					fill_stack_a_str(char **num_arr, int height,\
					t_stack_m *stack);
void				form_a(t_stack_m *stack);
void				found_command(t_stack_m *stack, int j);
void				found_min_elem_b(t_stack_m *stack);
int					found_place_a(t_stack_m *stack, int j);
int					ft_abs(int a);
int					ft_isnum(char *str);
void				ft_swap_int(int *a, int *b);
void				free_stacks(t_stack_m *stack);
int					head_in_bottom(t_stack_m *stack, int j);
int					head_in_top(t_stack_m *stack, int j);
int					init_i(t_stack_m *stack);
void				init_index(t_stack *stack, int	size);
int					init_stack(t_stack *stack);
void				init_stacks(t_stack_m *stack);
int					less_then_head(t_stack_m *stack);
void				make_max_length_arr(t_stack_m *stack);
int					make_stack(int argc, char **argv, t_stack_m *stack);
int					max_int_array(int *array, int size);
int					max_lenght_arr(t_stack_m *stack, int size);
int					max_two_int(int a, int b);
int					min_four_int(int a, int b, int c, int d);
int					min_int_array(int *array, int size);
void				move_from_b_to_a(t_stack_m *stack);
void				pa_comm(t_stack_m *stack);
void				pa_command(t_stack_m *stack);
void				pasapa_comm(t_stack_m *stack);
void				pasarra_comm(t_stack_m *stack);
void				papa_comm(t_stack_m *stack);
void				parapa_comm(t_stack_m *stack);
void				parara_comm(t_stack_m *stack);
int					parse_arg_num(int i, int argc, char **argv);
int					parce_string_arg_num(char **num_arr, int height);
void				parce_option(t_stack_m *stack, int argc, char **argv);
void				pb_command(t_stack_m *stack);
void				print_usage(void);
void				ra_comm(t_stack_m *stack);
void				ra_command(t_stack_m *stack);
void				ra_gt_rb(t_stack_m *stack);
void				rara_comm(t_stack_m *stack);
void				rb_command(t_stack_m *stack);
void				rr_comm(t_stack_m *stack);
void				rr_command(t_stack_m *stack);
void				rra_comm(t_stack_m *stack);
void				rra_command(t_stack_m *stack);
void				rrb_comm(t_stack_m *stack);
void				rrb_command(t_stack_m *stack);
void				rraparara_comm(t_stack_m *stack);
void				rrr_comm(t_stack_m *stack);
void				rrr_command(t_stack_m *stack);
void				rara_comm(t_stack_m *stack);
void				rarb_mix_command(t_stack_m *stack);
void				rarrb_mix_command(t_stack_m *stack);
void				rrarb_mix_command(t_stack_m *stack);
void				rrarrb_mix_command(t_stack_m *stack);
void				sa_comm(t_stack_m *stack);
void				sa_command(t_stack_m *stack);
void				sara_comm(t_stack_m *stack);
void				sarra_comm(t_stack_m *stack);
void				sb_comm(t_stack_m *stack);
void				sb_command(t_stack_m *stack);
void				sort_int_3(t_stack_m *stack);
void				sort_int_4(t_stack_m *stack);
void				sort_int_5(t_stack_m *stack);
int					sorter(t_stack_m *stack);
int					stack_bottom(t_stack_m *stack);

#endif
