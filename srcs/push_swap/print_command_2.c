/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/19 00:23:31 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_comm(t_stack_m *stack)
{
	stack->num_comm++;
	sb_command(stack);
	ft_printf("%wsb\n", stack->fd);
}

void	pa_comm(t_stack_m *stack)
{
	stack->num_comm++;
	pa_command(stack);
	ft_printf("%wpa\n", stack->fd);
}

void	papa_comm(t_stack_m *stack)
{
	pa_comm(stack);
	pa_comm(stack);
}

void	rara_comm(t_stack_m *stack)
{
	ra_comm(stack);
	ra_comm(stack);
}

void	pasapa_comm(t_stack_m *stack)
{
	pa_comm(stack);
	sa_comm(stack);
	pa_comm(stack);
}
