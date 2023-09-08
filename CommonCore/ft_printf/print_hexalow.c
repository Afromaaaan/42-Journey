/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:25:21 by jbaeza-c          #+#    #+#             */
/*   Updated: 2023/09/08 11:25:21 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "libprintf.h"

void	print_hexalow(va_list args, int fd)
{
	int	value;

	value = va_arg(args, int);
	ft_putnbru_base_fd(value, "0123456789abcdef", fd);
}
