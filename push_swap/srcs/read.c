/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 13:30:47 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:47:18 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stacks(t_p *p, int n)
{
	p->nb = 0;
	p->a = (int *)malloc(sizeof(int) * n);
	p->b = (int *)malloc(sizeof(int) * n);
}

int		split_input(char **arr, t_p *p)
{
	int		i;
	char	*str;

	i = ft_arrlen(arr) - 1;
	p->na = 0;
	create_stacks(p, i + 1);
	while (i >= 0)
	{
		str = ft_itoa(ft_atoi(arr[i]));
		if (strcmp(arr[i], str) || isdouble(i + 1, arr))
		{
			if (arr)
				ft_arrdel(arr);
			ft_strdel(&str);
			return (1);
		}
		p->a[p->na++] = ft_atoi(arr[i]);
		i--;
		ft_strdel(&str);
	}
	if (arr)
		ft_arrdel(arr);
	return (0);
}

int		read_file(char *name, t_p *p)
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
	split_input(arr, p);
	ft_strdel(&buffer);
	return (1);
}

void	read_arg(int argc, char **argv, t_p *p)
{
	int	i;

	i = 0;
	p->na = 0;
	create_stacks(p, argc - 1);
	while (argc > 1)
	{
		if (!check_flag(argv[argc - 1]))
		{
			p->a[i] = ft_atoi(argv[argc - 1]);
			p->na++;
			i++;
		}
		argc--;
	}
}

int		read_input(int argc, char **argv, t_p *p)
{
	char	**arr;

	arr = ft_strsplit(argv[1], ' ');
	if (ft_arrlen(arr) > 1)
	{
		if (split_input(arr, p))
			return (1);
	}
	else
	{
		if (arr)
			ft_arrdel(arr);
		read_arg(argc, argv, p);
	}
	return (0);
}
