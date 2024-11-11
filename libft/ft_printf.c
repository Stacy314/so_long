/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:40:46 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/23 16:55:33 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit((long)va_arg(ap, int), 10, specifier));
	else if (specifier == 'x' || specifier == 'X')
		return (print_digit((long)va_arg(ap, unsigned int), 16, specifier));
	else if (specifier == 'u')
		return (print_digit((long)va_arg(ap, unsigned int), 10, specifier));
	else if (specifier == 'p')
		return (print_address(va_arg(ap, unsigned long)));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
}

int	print_digit(long n, int base, char specifier)
{
	int		i;
	char	*symbols;
	char	*symbols_upper;

	i = 0;
	symbols = "0123456789abcdef";
	symbols_upper = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, 'x') + 1);
	}
	else if (n < base)
	{
		if (specifier == 'X')
			return (ft_putchar_fd(symbols_upper[n], 1));
		return (ft_putchar_fd(symbols[n], 1));
	}
	else
	{
		i = print_digit(n / base, base, specifier);
		return (i + print_digit(n % base, base, specifier));
	}
}

int	print_digit_u(unsigned long n, int base, char specifier)
{
	int		i;
	char	*symbols;

	i = 0;
	symbols = "0123456789abcdef";
	if (n < (unsigned long)base)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		i = print_digit_u(n / base, base, specifier);
		return (i + print_digit_u(n % base, base, specifier));
	}
}

int	print_address(unsigned long address)
{
	int				len;

	len = 0;
	if (!address)
		len += ft_putstr_fd("(nil)", 1);
	else
	{
		len = ft_putstr_fd("0x", 1);
		len += print_digit_u(address, 16, 'x');
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i += print_format(*(++format), ap);
		}
		else
		{
			i += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (i);
}

/*int main()
{
    int count;

    count = ft_printf("%d\n", 255);
    printf("The chars written are %d\n", count);
    count = printf("%d\n", 255);
    printf("The chars written are %d\n", count);
    return (0);
}*/