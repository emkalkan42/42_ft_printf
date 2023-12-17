/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:45:46 by emkalkan          #+#    #+#             */
/*   Updated: 2023/10/15 14:45:46 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

// Function to print a character and return 1 (character count)
int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// Function to handle different format specifiers
int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

// Main printf function that handles format specifiers in the input string
// If '%' is encountered, call ft_formats to handle the format specifier
// If no format specifier is found, print the character
int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			print_length;

	i = 0;
	print_length = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			print_length += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}