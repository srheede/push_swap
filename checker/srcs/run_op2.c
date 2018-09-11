/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:22:21 by srheede           #+#    #+#             */
/*   Updated: 2018/08/27 18:07:04 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_pa(t_check *check)
{
	if (check->n_a > 0)
	{
		check->n_b++;
		ft_swap(&check->a[check->n_a - 1], &check->b[check->n_b - 1]);
		check->n_a--;
	}
}

void	do_pb(t_check *check)
{
	if (check->n_b > 0)
	{
		check->n_a++;
		ft_swap(&check->a[check->n_a - 1], &check->b[check->n_b - 1]);
		check->n_b--;
	}
}

void	do_rra(t_check *check)
{
	int	i;
	int	tmp;

	if (check->n_a > 0)
	{
		tmp = check->a[0];
		i = 0;
		while (i < check->n_a)
		{
			check->a[i] = check->a[i + 1];
			i++;
		}
		check->a[check->n_a - 1] = tmp;
	}
}

void	do_rrb(t_check *check)
{
	int	i;
	int	tmp;

	if (check->n_b > 0)
	{
		tmp = check->b[0];
		i = 0;
		while (i < check->n_b)
		{
			check->b[i] = check->b[i + 1];
			i++;
		}
		check->b[check->n_b - 1] = tmp;
	}
}

void	do_rrr(t_check *check)
{
	check->call = 0;
	do_rra(check);
	do_rrb(check);
}
