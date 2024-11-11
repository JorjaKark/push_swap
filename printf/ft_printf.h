/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:10:20 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/08 15:33:38 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int nbr, int lcase);
int	print_pointer(unsigned long nbr, int flag);
int	ft_printf(const char *format, ...);

#endif
