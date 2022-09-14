/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:41:02 by shan              #+#    #+#             */
/*   Updated: 2022/04/27 13:01:24 by shan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print(char c, va_list ap, int *i)
{
	if (c == '%')
		(*i) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*i) += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		(*i) += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		(*i) += ft_putstr(va_arg(ap, char *));
	else if (c == 'x')
		(*i) += ft_hexa(va_arg(ap, unsigned int), 1);
	else if (c == 'X')
		(*i) += ft_hexa(va_arg(ap, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		(*i) += 2;
		(*i) += ft_hexa(va_arg(ap, unsigned long), 1);
	}
	else if (c == 'u')
		(*i) += ft_unsigned(va_arg(ap, unsigned int));
	else
		(*i) += ft_putchar(c);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, form);
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '\0')
				return (i);
			print(*form, ap, &i);
		}
		else
		{
			ft_putchar(*form);
			i++;
		}
		form++;
	}
	va_end(ap);
	return (i);
}
