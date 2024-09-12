/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:39:51 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/04/22 10:21:45 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
