/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:55:29 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_zero(t_p *p)
{
	p->buffer = NULL;
	p->a = NULL;
	p->b = NULL;
	p->na = 0;
	p->nb = 0;
	p->debug = 0;
	p->end = 0;
	p->file = 0;
	p->step = 0;
	p->visualize = 0;
	p->max = 0;
	p->tmp = 0;
	p->next = 0;
	p->d = 0;
	p->direction_max = 0;
	p->direction_min = 0;
	p->shift = 0;
	p->min_n = 0;
	p->max_n = 0;
	p->size = 0;
	p->alternate = 0;
}

void	read_flags(int argc, char **argv, t_p *p)
{
	int		i;

	i = 1;
	set_zero(p);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-d"))
			p->debug = 1;
		if (!ft_strcmp(argv[i], "-e"))
			p->end = 1;
		if (!ft_strcmp(argv[i], "-f"))
			p->file = 1;
		if (!ft_strcmp(argv[i], "-s"))
			p->step = 1;
		i++;
	}
}

void	sort(t_p *p)
{
	if (p->na < 14)
		strat3(p);
	else
		part(p);
}

void	delmem(t_p *p, int err)
{
	if (p->a)
		free(p->a);
	if (p->b)
		free(p->b);
	if (err)
		ft_putstr("Error\n");
}

int		main(int argc, char **argv)
{
	t_p	p;

	if (argc > 1)
	{
		read_flags(argc, argv, &p);
		if (!p.file)
		{
			if (error_check(argc, argv) || read_input(argc, argv, &p))
			{
				delmem(&p, 1);
				return (-1);
			}
		}
		else
		{
			if (!read_file(argv[1], &p))
			{
				delmem(&p, 1);
				return (-1);
			}
		}
		sort(&p);
		delmem(&p, 0);
	}
	return (0);
}
