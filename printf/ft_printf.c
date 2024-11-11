/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:09:46 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/08 14:48:51 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str != '\0')
	{
		count += print_char((int)*str++);
	}
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_hex(va_arg(ap, unsigned int), 1);
	else if (specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), 0);
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, unsigned long), 0);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{

	char c = '7'; // %c
	char *str = "String test"; // %s
	char *var; var = &c;// %p
	int    nbr = -590888;// %d // %i
	unsigned int nbrr = 200;// %u
	int b= 0xffa1234;// %x // %X
	// %%

	int i;
	printf("Printf replica:\n");
	i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String:
			%s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer
			%i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper:
			%X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b,
			b);
	printf("\nReturn Value: %d", i);
	///////////////////////////////
	printf("\nPrintf original:\n");
	i = printf("| TEST TEXT |\n| Single Char: %c |\n| String:
			%s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer
			%i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper:
			%X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b,
			b);
	printf("\nReturn Value: %d\n", i);
	return (0);
}*/
