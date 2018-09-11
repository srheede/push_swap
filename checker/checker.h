/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:43:57 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:55:35 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <libc.h>

typedef struct	s_check
{
	char		*buffer;
	int			*a;
	int			*b;
	int			n_a;
	int			n_b;
	int			debug;
	int			file;
	int			call;
}				t_check;

void			issorted(t_check *check);
int				check_flag(char *str);
int				error_check(int argc, char **argv);
void			putstacks(t_check check);
int				read_file(char *name, t_check *check);
int				read_input(int argc, char **argv, t_check *check);
int				isdouble(int argc, char **argv);
void			do_pa(t_check *check);
void			do_pb(t_check *check);
void			do_ra(t_check *check);
void			do_rb(t_check *check);
void			do_rr(t_check *check);
void			do_rra(t_check *check);
void			do_rrb(t_check *check);
void			do_rrr(t_check *check);
void			run_op(t_check *check);

#endif
