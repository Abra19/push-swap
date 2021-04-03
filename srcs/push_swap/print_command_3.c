/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/19 00:39:12 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rraparara_comm(t_stack_m *stack)
{
	rra_comm(stack);
	pa_comm(stack);
	ra_comm(stack);
	ra_comm(stack);
}

void	pasarra_comm(t_stack_m *stack)
{
	pa_comm(stack);
	sa_comm(stack);
	rra_comm(stack);
}

void	parara_comm(t_stack_m *stack)
{
	pa_comm(stack);
	ra_comm(stack);
	ra_comm(stack);
}

void	parapa_comm(t_stack_m *stack)
{
	pa_comm(stack);
	ra_comm(stack);
	pa_comm(stack);
}

void	rr_comm(t_stack_m *stack)
{
	stack->num_comm++;
	rr_command(stack);
	ft_printf("%wrr\n", stack->fd);
}
