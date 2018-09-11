/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:49:52 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:55:32 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	issorted(t_check *check)
{
	int	i;
	int	err;

	err = 0;
	if (check->n_b)
		err++;
	i = 0;
	while (i < check->n_a - 1)
	{
		if (check->a[i] < check->a[i + 1])
			err++;
		i++;
	}
	err ? ft_putstr("KO\n") : ft_putstr("OK\n");
}

int		check_flag(char *str)
{
	int	err;

	err = 0;
	if (!ft_strcmp(str, "-d"))
		err++;
	if (!ft_strcmp(str, "-f"))
		err++;
	if (!err)
		return (0);
	return (1);
}

int		isdouble(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_arg(int argc, char **argv, char *str)
{
	char *number;

	number = ft_itoa(ft_atoi(str));
	if (!check_flag(str) && strcmp(str, number))
	{
		ft_strdel(&number);
		return (1);
	}
	else if (isdouble(argc, argv))
	{
		ft_strdel(&number);
		return (1);
	}
	ft_strdel(&number);
	return (0);
}

int		error_check(int argc, char **argv)
{
	int		i;
	char	**arr;

	i = 1;
	arr = ft_strsplit(argv[1], ' ');
	if (arr)
	{
		if (ft_arrlen(arr) > 1)
			i++;
		ft_arrdel(arr);
	}
	while (i < argc)
	{
		if (check_arg(argc, argv, argv[i]))
			return (1);
		i++;
	}
	return (0);
}
