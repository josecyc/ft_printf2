/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:21:11 by jcruz-y-          #+#    #+#             */
/*   Updated: 2018/09/17 19:11:30 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_conditions(char fmt)
{
	if (fmt != '%' && fmt != 'd' && fmt != 'c' && fmt != 's')
	{
		return (1);
	}
	return (0);
}

void	itoa_base(unsigned long num, unsigned long base, int *count)
{
	if (num < base)
	{
		if (num >= 10 && num <= 15)
			ft_putchar(num + 87, count);
		else
			ft_putchar(num + '0', count);
	}
	else
	{
		itoa_base(num / base, base, count);
		itoa_base(num % base, base, count);
	}
}

void	px_itoa_base(unsigned long num, unsigned long base, int *count)
{
	if (base == 16)
		ft_putstr("0x", count);
	itoa_base(num, base, count);
}

void	ft_cases(char *fmt, va_list ap, int *count)
{
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == 's' && fmt++)
			ft_putstr(va_arg(ap, char *), count);
		else if (*fmt == '%' && (*(fmt + 1) == 'd' ||
				*(fmt + 1) == 'i') && fmt++)
			ft_putnbr(va_arg(ap, int), count);
		else if (*fmt == '%' && (*(fmt + 1) == 'o') && fmt++)
			itoa_base(va_arg(ap, unsigned long), 8, count);
		else if (*fmt == '%' && (*(fmt + 1) == 'p') && fmt++)
			px_itoa_base(va_arg(ap, unsigned long), 16, count);
		else if (*fmt == '%' && (*(fmt + 1) == 'u') && fmt++)
			itoa_base(va_arg(ap, unsigned long), 10, count);
		else if (*fmt == '%' && (*(fmt + 1) == 'x') && fmt++)
			itoa_base(va_arg(ap, unsigned long), 16, count);
		else if (*fmt == '%' && *(fmt + 1) == 'c' && fmt++)
			ft_putchar(va_arg(ap, int), count);
		else if (*fmt == '%' && *(fmt + 1) == '%' && fmt++)
			ft_putchar(*fmt, count);
		else
			ft_putchar(*fmt, count);
		fmt++;
	}
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		*count;

	count = (int *)malloc(4);
	*count = 0;
	va_start(ap, fmt);
	ft_cases(fmt, ap, count);
	va_end(ap);
	return (*count);
}
