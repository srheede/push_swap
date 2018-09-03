/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:06:59 by srheede           #+#    #+#             */
/*   Updated: 2018/06/20 14:08:00 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putarr_fd(char **arr, int fd)
{
	while (*arr)
	{
		ft_putstr_fd(*arr, fd);
		arr++;
	}
}
