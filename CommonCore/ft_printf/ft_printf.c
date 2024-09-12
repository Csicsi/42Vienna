/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:16:40 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/04/17 14:03:19 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, placeholders);
	if (placeholders == NULL)
		return (-1);
	while (*placeholders != '\0')
	{
		if (*placeholders == '%')
		{
			if (in_set("cspdiuxX%", *(++placeholders)))
				len += handle_format(*placeholders, args);
			else
				return (-1);
		}
		else
		{
			write(1, placeholders, 1);
			len++;
		}
		placeholders++;
	}
	va_end(args);
	return (len);
}
