/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbracket_open.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 07:14:14 by srheede           #+#    #+#             */
/*   Updated: 2018/06/15 07:15:17 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_isbracket_open(int c)
{
	if (c == '(' || c == '{' || c == '[')
		return (1);
	return (0);
}