/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:09:21 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/08 14:39:46 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			count += write(1, "-", 1);
			count += print_digit(-n);
		}
		else if (n / 10 == 0)
		{
			n += 48;
			count += write(1, &n, 1);
		}
		else
		{
			count += print_digit(n / 10);
			count += print_digit(n % 10);
		}
	}
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10 == 0)
	{
		n += 48;
		count += write(1, &n, 1);
	}
	else
	{
		count += print_unsigned(n / 10);
		count += print_unsigned(n % 10);
	}
	return (count);
}

int	print_hex(unsigned int nbr, int lcase)
{
	char	c;
	int		count;

	count = 0;
	if (nbr >= 16)
		count += print_hex(nbr / 16, lcase);
	if (nbr % 16 < 10)
		c = nbr % 16 + '0';
	else
	{
		if (lcase)
			c = nbr % 16 + 'a' - 10;
		else
			c = nbr % 16 + 'A' - 10;
	}
	return (count + write(1, &c, 1));
}

int	print_pointer(unsigned long nbr, int flag)
{
	int		count;
	char	c;

	count = 0;
	if (!nbr)
		return (write(1, "(nil)", 5));
	if (count == 0 && !flag)
		count += write(1, "0x", 2);
	if (nbr >= 16)
		count += print_pointer(nbr / 16, 1);
	if ((nbr % 16) < 10)
		c = nbr % 16 + '0';
	else
		c = nbr % 16 - 10 + 'a';
	return (count + write(1, &c, 1));
}
