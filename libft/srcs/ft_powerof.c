/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:23:53 by srheede           #+#    #+#             */
/*   Updated: 2018/03/18 03:46:46 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_powerof(int nb, int power)
{
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_powerof(nb, power - 1));
}