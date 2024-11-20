/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:29 by mgamraou          #+#    #+#             */
/*   Updated: 2024/11/20 15:18:08 by mgamraou         ###   ########.fr       */
/*                                                                             */
/* ************************************************************************** */

#include "libft.h"

int ft_count(unsigned long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_convert(unsigned long int n)
{
	if (n >= 16)
	{
		ft_convert(n/16);
		ft_convert(n%16);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
			ft_putchar(((n - 10) + 'a'));
	}
}
int ft_putaddress(void *ptr)
{
	int printed;
	unsigned long int cast;

	printed = 0;
	cast = (unsigned long int)ptr;
	printed = ft_count(cast);
	ft_putstr("0x");
	printed += 2;
	ft_convert(cast);
	return (printed);
}
