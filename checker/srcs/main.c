/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:55:37 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	delmem(t_check *check, int err)
{
	if (check->a)
		free(check->a);
	if (check->b)
		free(check->b);
	if (err)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	get_ops(t_check *check)
{
	while (get_next_line(0, &check->buffer))
	{
		if (!ft_strcmp(check->buffer, "end"))
			break ;
		run_op(check);
		if (check->debug)
			putstacks(*check);
		ft_strdel(&check->buffer);
	}
	if (check->buffer)
		ft_strdel(&check->buffer);
	issorted(check);
	delmem(check, 0);
}

void	set_zero(t_check *check)
{
	check->buffer = NULL;
	check->a = NULL;
	check->b = NULL;
	check->n_a = 0;
	check->n_b = 0;
	check->debug = 0;
	check->file = 0;
	check->call = 0;
}

void	read_flags(int argc, char **argv, t_check *check)
{
	int	i;

	i = 1;
	set_zero(check);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-d"))
			check->debug = 1;
		if (!ft_strcmp(argv[i], "-f"))
			check->file = 1;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_check	check;

	if (argc > 1)
	{
		read_flags(argc, argv, &check);
		if (!check.file)
		{
			if (error_check(argc, argv) || read_input(argc, argv, &check))
				delmem(&check, 1);
		}
		else
		{
			if (!read_file(argv[1], &check))
				delmem(&check, 1);
		}
		get_ops(&check);
	}
	return (0);
}
