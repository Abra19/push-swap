/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/20 20:59:24 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_comm(t_stack_m *stack)
{
	stack->num_comm++;
	rrr_command(stack);
	ft_printf("%wrrr\n", stack->fd);
}

void	rrb_comm(t_stack_m *stack)
{
	stack->num_comm++;
	rrb_command(stack);
	ft_printf("%wrrb\n", stack->fd);
}
