/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:33:36 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/23 13:46:53 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_printint(va_arg(args, int)));
	else if (format == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_printhexa(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_printhexa2(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printchar('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += ft_format(args, s[i + 1]);
			i++;
		}
		else
			count += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	// char			c = 'a';
// 	// char			a[] = "";
// 	// int				var = -2147483648;
// 	// int				i = 7;
// 	// unsigned int 	u = 3147483647;

// 	// int 			count;

// 	// count = ft_printf("%c %s %p %d %i yoo %u %x %X %%",
//  c, a, (void *)&var, var, i, u, u, u);
// 	// ft_printf("\n%d", count);

// 	// printf("\n\n");

// 	// count = printf("%c %s %p %d %i yoo %u %x %X %%",
//  c, a, (void *)&var, var, i, u, u, u);
// 	// printf("\n%d", count);
// 	ft_printf(" %s %s %s %s ", " - ", "", "4", "");
// }