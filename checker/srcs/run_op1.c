/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:22:36 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 16:12:38 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_sa(t_check *check)
{
	if (check->n_a > 1)
		ft_swap(&check->a[check->n_a - 1], &check->a[check->n_a - 2]);
}

void	do_sb(t_check *check)
{
	if (check->n_b > 1)
		ft_swap(&check->b[check->n_b - 1], &check->b[check->n_b - 2]);
}

void	do_ss(t_check *check)
{
	do_sa(check);
	do_sb(check);
}

void	run_op(t_check *check)
{
	if (!ft_strcmp(check->buffer, "sa"))
		do_sa(check);
	else if (!ft_strcmp(check->buffer, "sb"))
		do_sb(check);
	else if (!ft_strcmp(check->buffer, "ss"))
		do_ss(check);
	else if (!ft_strcmp(check->buffer, "pb"))
		do_pa(check);
	else if (!ft_strcmp(check->buffer, "pa"))
		do_pb(check);
	else if (!ft_strcmp(check->buffer, "ra"))
		do_ra(check);
	else if (!ft_strcmp(check->buffer, "rb"))
		do_rb(check);
	else if (!ft_strcmp(check->buffer, "rr"))
		do_rr(check);
	else if (!ft_strcmp(check->buffer, "rra"))
		do_rra(check);
	else if (!ft_strcmp(check->buffer, "rrb"))
		do_rrb(check);
	else if (!ft_strcmp(check->buffer, "rrr"))
		do_rrr(check);
	else
		delmem(check, 1);
}
