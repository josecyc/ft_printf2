/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:24:24 by jcruz-y-          #+#    #+#             */
/*   Updated: 2018/09/17 19:13:42 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', count);
	}
	if (nb < 10)
	{
		nb = nb + '0';
		ft_putchar(nb, count);
	}
	else
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
}
