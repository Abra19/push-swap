/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/18 23:29:41 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_comm(t_stack_m *stack)
{
	stack->num_comm++;
	sa_command(stack);
	ft_printf("%wsa\n", stack->fd);
}

void	rra_comm(t_stack_m *stack)
{
	stack->num_comm++;
	rra_command(stack);
	ft_printf("%wrra\n", stack->fd);
}

void	ra_comm(t_stack_m *stack)
{
	stack->num_comm++;
	ra_command(stack);
	ft_printf("%wra\n", stack->fd);
}

void	sarra_comm(t_stack_m *stack)
{
	sa_comm(stack);
	rra_comm(stack);
}

void	sara_comm(t_stack_m *stack)
{
	sa_comm(stack);
	ra_comm(stack);
}
