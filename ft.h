/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:05:44 by jcruz-y-          #+#    #+#             */
/*   Updated: 2018/09/17 19:12:01 by jcruz-y-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putchar(char c, int *count);
size_t	ft_strlen(const char *str);

#endif
