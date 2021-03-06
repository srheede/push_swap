/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:04:11 by srheede           #+#    #+#             */
/*   Updated: 2018/06/26 07:59:05 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putarr_sp(char **arr)
{
	while (*arr)
	{
		ft_putstr(*arr);
		ft_putchar(' ');
		arr++;
	}
}
