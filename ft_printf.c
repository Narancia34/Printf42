/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:32:42 by mgamraou          #+#    #+#             */
/*   Updated: 2024/11/20 15:41:00 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formatcheck(va_list args, const char c)
{
	int printed;

	printed = 0;
	if (c == '%')
		printed = ft_putchar('%');
	else if (c == 'c')
		printed = ft_putchar(va_arg(args, int));
	else if (c == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		printed = ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		printed = ft_puthexa(va_arg(args, int), c);
	else if (c == 'p')
		printed = ft_putaddress(va_arg(args, void *));
	return (printed);
}

int	ft_printf(const char *formats, ...)
{
	va_list	args;
	int	i;
	int printed;
	
	i = 0;
	printed = 0;
	va_start(args, formats);
	while (formats[i])
	{
		if (formats[i] == '%')
		{
			i++;
			printed += ft_formatcheck(args, formats[i]);
			i++;
		}
		else
		{
			ft_putchar(formats[i]);
			printed++;
			i++;
		}
	}
	va_end(args);
	return (printed);
}
// int main ()
// {
// 	int i = ft_printf("%p", 4568, 13);
// 	ft_printf("\n%d", i);
// }