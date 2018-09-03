/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:43:57 by srheede           #+#    #+#             */
/*   Updated: 2018/08/29 17:50:08 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <libc.h>

typedef struct	s_mlx
{
	void		*disp_link;
	void		*win;
	char		**map;
}				t_mlx;

typedef struct	s_p
{
	char		*buffer;
	int			*a;
	int			*b;
	int			na;
	int			nb;
	int			colour;
	int			debug;
	int			end;
	int			file;
	int			step;
	int			visualize;
	int			max;
	int			tmp;
	int			next;
	int			d;
	int			direction_max;
	int			direction_min;
	int			shift;
	int			min_n;
	int			max_n;
	int			size;
	int			alternate;
}				t_p;

void			sort_to_b(t_p *p);
void			partition(int *sorted, int n_sorted, t_p *p);
void			part_to_a1(t_p *p);
void			find_next(t_p *p);
int				check_flag(char *str);
int				error_check(int argc, char **argv);
void			part(t_p *p);
int				read_file(char *name, t_p *p);
int				read_input(int argc, char **argv, t_p *p);
void			putstacks(t_p *p);
int				issorted(t_p *p);
int				isdouble(int argc, char **argv);
void			do_sa(t_p *p);
void			do_sb(t_p *p);
void			do_ss(t_p *p);
void			do_pa(t_p *p);
void			do_pb(t_p *p);
void			do_ra(t_p *p);
void			do_rb(t_p *p);
void			do_rr(t_p *p);
void			do_rra(t_p *p);
void			do_rrb(t_p *p);
void			do_rrr(t_p *p);
void			run_op(t_p *p);
void			strat3(t_p *p);
int				iscross_sorted(t_p *p);

#endif
