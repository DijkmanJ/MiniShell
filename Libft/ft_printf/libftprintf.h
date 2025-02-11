/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:27:04 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/10 18:47:42 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "libftprintf.h"

int		ft_printf(const char *s, ...);
int		ft_format(va_list args, const char format);
int		ft_printstr(const char *s);
int		ft_printchar(int c);
int		ft_printint(int c);
void	ft_printint2(int c);
int		ft_printptr(void *ptr);
void	ft_printptr2(unsigned long long addr);
int		ft_ptrlen(unsigned long long addr);
int		ft_printunsigned(unsigned int c);
void	ft_printunsigned2(unsigned int c);
int		ft_printhexa(unsigned int c);
void	ft_hexa(unsigned int c);
int		ft_hexalen(unsigned int c);
int		ft_printhexa2(unsigned int c);
void	ft_hexa2(unsigned int c);

#endif