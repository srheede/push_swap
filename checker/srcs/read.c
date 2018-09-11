/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 13:30:47 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:43:26 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	create_stacks(t_check *check, int n)
{
	check->n_b = 0;
	check->a = (int *)malloc(sizeof(int) * n);
	check->b = (int *)malloc(sizeof(int) * n);
}

int		split_input(char **arr, t_check *check)
{
	int		i;
	char	*str;

	i = ft_arrlen(arr) - 1;
	check->n_a = 0;
	create_stacks(check, i + 1);
	while (i >= 0)
	{
		str = ft_itoa(ft_atoi(arr[i]));
		if (strcmp(arr[i], str))
		{
			if (arr)
				ft_arrdel(arr);
			ft_strdel(&str);
			return (1);
		}
		check->a[check->n_a++] = ft_atoi(arr[i]);
		i--;
		ft_strdel(&str);
	}
	if (arr)
		ft_arrdel(arr);
	return (0);
}

int		read_file(char *name, t_check *check)
{
	int		fd;
	char	*buffer;
	char	**arr;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd, &buffer);
	close(fd);
	arr = ft_strsplit(buffer, ' ');
	split_input(arr, check);
	ft_strdel(&buffer);
	return (1);
}

void	read_arg(int argc, char **argv, t_check *check)
{
	int		i;

	i = 0;
	check->n_a = 0;
	create_stacks(check, argc - 1);
	while (argc > 1)
	{
		if (!check_flag(argv[argc - 1]))
		{
			check->a[i] = ft_atoi(argv[argc - 1]);
			check->n_a++;
			i++;
		}
		argc--;
	}
}

int		read_input(int argc, char **argv, t_check *check)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(argv[1], ' ');
	if (ft_arrlen(arr) > 1)
	{
		if (split_input(arr, check))
			return (1);
	}
	else
	{
		if (arr)
			ft_arrdel(arr);
		read_arg(argc, argv, check);
	}
	return (0);
}
