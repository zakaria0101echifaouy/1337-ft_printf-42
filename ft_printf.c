/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:03:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/10 23:11:25 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// va_arg(args, type ) type = int or char or char * ...

int	ft_printf(const char * str, ...)
{
	size_t	i;
	va_list	args;
	va_start(args, str);

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
		{
			i++;
			if (str[i] == '\0')
				continue;
			else if (str[i] == '%')
				ft_putchar('%');
			else if (str[i] == 'c')
				ft_putchar((char)va_arg(args, int));
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (str[i] == 'p')
				continue;
			else if (str[i] == 'd')
				ft_convert(va_arg(args, int), 10, "0123456789");
			else if (str[i] == 'i')
				ft_convert(va_arg(args, int), 10, "0123456789");
			else if (str[i] == 'u')
				continue;
			else if (str[i] == 'x')
				ft_convert(va_arg(args, int), 16, "0123456789abcdef");
			else if (str[i] == 'X')
				ft_convert(va_arg(args, int), 16, "0123456789ABCDEF");
		}
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("%s , %d , %c, %f \n", "world", 1337, 'z', 6.888);
	return (0);
}