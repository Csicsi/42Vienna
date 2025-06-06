/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:28:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/12 13:28:58 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_fprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			total_len;
	char		*buffer;

	va_start(args, format);
	total_len = ft_calculate_total_len(format, args);
	va_end(args);
	buffer = malloc(total_len + 1);
	if (!buffer)
		return ;
	va_start(args, format);
	ft_fill_buffer(buffer, format, args);
	va_end(args);
	write(fd, buffer, total_len);
	free(buffer);
}
