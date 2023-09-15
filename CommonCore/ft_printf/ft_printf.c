/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:12 by jbaeza-c          #+#    #+#             */
/*   Updated: 2023/09/14 18:30:10 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include "stdio.h"

static void	check_case(int value, va_list args, int fd,
	t_print *strategy_method)
{
	t_print	strategy;
	
	strategy = strategy_method[value];
	if (strategy.execute)
		strategy.execute(args, fd);
	else
		ft_putchar_fd(value, fd);
}

static t_print	*strategy_create(size_t size)
{
	t_print	*strategy_method;

	strategy_method = (t_print *)ft_calloc(size, sizeof(t_print));
	strategy_method['d'] = (t_print){.execute = print_integer};
	strategy_method['i'] = (t_print){.execute = print_integer};
	strategy_method['u'] = (t_print){.execute = print_decimal};
	strategy_method['o'] = (t_print){.execute = print_octal};
	strategy_method['x'] = (t_print){.execute = print_hexalow};
	strategy_method['X'] = (t_print){.execute = print_hexaup};
	strategy_method['c'] = (t_print){.execute = print_char};
	strategy_method['s'] = (t_print){.execute = print_string};
	strategy_method['p'] = (t_print){.execute = print_ptr};
	return (strategy_method);
}

int	ft_printf(const char *format, ...)
{
	t_print	*strategy_method;
	va_list	args;
	int		i;

	va_start(args, format);
	strategy_method = strategy_create(128);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			check_case(format[i], args, 1, strategy_method);
		}
		else
			ft_putchar_fd(format[i], 1);
	}
	free(strategy_method);
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%c", '0');
	printf("%c", '0');
	return (0);
}