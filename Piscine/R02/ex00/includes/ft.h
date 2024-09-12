/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalajqi <lalajqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:06:24 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/03/03 23:03:19 by lalajqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define MAX_LINE_LENGTH 256
# define MAX_ENTRIES 100 // Replace 100 with the number of entries

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_dict
{
	t_entry	*entries;
	int		size;
}	t_dict;

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_strchr(const char *str, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *s);
int		ft_strlen(const char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
void	free_dictionary(t_dict *dictionary);

#endif
