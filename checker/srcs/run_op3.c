/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:23:00 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 16:14:39 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	putstacks(t_check check)
{
	int i;

	ft_putstr_fd("Stack A: ", 2);
	i = check.n_a - 1;
	while (i >= 0)
	{
		ft_putnbr_fd(check.a[i], 2);
		ft_putchar_fd(' ', 2);
		i--;
	}
	ft_putstr_fd("\nStack B: ", 2);
	i = check.n_b - 1;
	while (i >= 0)
	{
		ft_putnbr_fd(check.b[i], 2);
		ft_putchar_fd(' ', 2);
		i--;
	}
	ft_putchar_fd('\n', 2);
}

void	do_ra(t_check *check)
{
	int	i;
	int	tmp;

	if (check->n_a > 0)
	{
		tmp = check->a[check->n_a - 1];
		i = check->n_a - 1;
		while (i > 0)
		{
			check->a[i] = check->a[i - 1];
			i--;
		}
		check->a[0] = tmp;
	}
}

void	do_rb(t_check *check)
{
	int	i;
	int	tmp;

	if (check->n_b > 0)
	{
		tmp = check->b[check->n_b - 1];
		i = check->n_b - 1;
		while (i > 0)
		{
			check->b[i] = check->b[i - 1];
			i--;
		}
		check->b[0] = tmp;
	}
}

void	do_rr(t_check *check)
{
	do_ra(check);
	do_rb(check);
}
