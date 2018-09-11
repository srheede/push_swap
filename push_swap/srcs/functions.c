/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:53:17 by srheede           #+#    #+#             */
/*   Updated: 2018/08/27 16:50:37 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	putstacks(t_p *p)
{
	int	i;

	ft_putstr_fd("Stack A: ", 1);
	i = p->na - 1;
	while (i >= 0)
	{
		ft_putnbr_fd(p->a[i], 1);
		ft_putchar_fd(' ', 1);
		i--;
	}
	ft_putstr_fd("\nStack B: ", 1);
	i = p->nb - 1;
	while (i >= 0)
	{
		ft_putnbr_fd(p->b[i], 1);
		ft_putchar_fd(' ', 1);
		i--;
	}
	ft_putchar_fd('\n', 1);
}

int		issorted(t_p *p)
{
	int	i;
	int	err;

	err = 0;
	if (p->nb != 0)
		err++;
	i = 0;
	while (i < p->na - 1)
	{
		if (p->a[i] < p->a[i + 1])
			err++;
		i++;
	}
	if (err)
		return (0);
	if (p->end)
	{
		p->end = 0;
		ft_putstr("end\n");
	}
	return (1);
}

int		iscross_sorted(t_p *p)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < p->na - 1)
	{
		if (p->a[i] < p->a[i + 1])
			err++;
		i++;
	}
	i = 0;
	while (i < p->nb - 1)
	{
		if (p->b[i] > p->b[i + 1])
			err++;
		i++;
	}
	if (p->a[p->na - 1] < p->b[p->nb - 1])
		err++;
	if (err)
		return (0);
	return (1);
}

void	part(t_p *p)
{
	int	*sorted;

	sorted = NULL;
	sorted = ft_arrdup(p->a, p->na);
	p->tmp = p->na - 1;
	quicksort(sorted, 0, p->na - 1);
	p->max = 0;
	partition(sorted, p->na, p);
	if (sorted)
		free(sorted);
}
