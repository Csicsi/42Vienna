/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:42 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:27 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_signal_state
{
	size_t	len;
	size_t	bit_len;
	int		bit;
	int		len_flag;
	char	*str;
	size_t	str_index;
}	t_signal_state;

#endif
