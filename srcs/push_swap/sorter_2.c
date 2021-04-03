/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:19:13 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/25 01:55:35 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rarb_mix_command(t_stack_m *stack)
{
	int		i;

	i = 1;
	if (stack->ra >= stack->rb)
		ra_gt_rb(stack);
	else
	{
		while (i <= stack->ra)
		{
			rr_comm(stack);
			i++;
		}
		i = 1;
		while (i <= stack->rb - stack->ra)
		{
			stack->num_comm++;
			rb_command(stack);
			ft_printf("%wrb\n", stack->fd);
			i++;
		}
	}
	pa_comm(stack);
}

void	rarrb_mix_command(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i <= stack->ra)
	{
		ra_comm(stack);
		i++;
	}
	i = 1;
	while (i <= stack->rrb)
	{
		rrb_comm(stack);
		i++;
	}
	pa_comm(stack);
}

void	rrarb_mix_command(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i <= stack->rra)
	{
		rra_comm(stack);
		i++;
	}
	i = 1;
	while (i <= stack->rb)
	{
		stack->num_comm++;
		rb_command(stack);
		ft_printf("%wrb\n", stack->fd);
		i++;
	}
	pa_comm(stack);
}

void	rra_gt_rb(t_stack_m *stack)
{
	int		i;

	i = 1;
	while (i <= stack->rrb)
	{
		rrr_comm(stack);
		i++;
	}
	i = 1;
	while (i <= stack->rra - stack->rrb)
	{
		rra_comm(stack);
		i++;
	}
}

void	rrarrb_mix_command(t_stack_m *stack)
{
	int		i;

	i = 1;
	if (stack->rra >= stack->rrb)
		rra_gt_rb(stack);
	else
	{
		while (i <= stack->rra)
		{
			rrr_comm(stack);
			i++;
		}
		i = 1;
		while (i <= stack->rrb - stack->rra)
		{
			rrb_comm(stack);
			i++;
		}
	}
	pa_comm(stack);
}
