/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:06:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/04/22 10:23:41 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf_per(void);
int		ft_printf_di(int nbr);
int		ft_printf_c(int c);
int		ft_printf_s(char *str);
int		handle_format(char format, va_list args);
int		ft_printf_p(void *ptr);
int		ft_printf_u(unsigned int nbr);
int		ft_printf_xl(unsigned int nbr);
int		ft_printf_xc(unsigned int nbr);
int		in_set(const char *set, char c);
int		ft_printf(const char *placeholders, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *s);

#endif
