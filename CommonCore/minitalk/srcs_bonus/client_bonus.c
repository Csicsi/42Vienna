/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:45:32 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:45 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (c & (1 << i))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit (write(2, "Error sending signal\n", 22));
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit (write(2, "Error sending signal\n", 22));
		}
		while (!g_ack)
			pause();
		i++;
	}
}

void	send_len(pid_t server_pid, size_t len)
{
	size_t	i;

	i = 0;
	while (i < sizeof(size_t) * 8)
	{
		g_ack = 0;
		if (len & (1 << i))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit (write(2, "Error sending signal\n", 22));
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit (write(2, "Error sending signal\n", 22));
		}
		while (!g_ack)
			pause();
		i++;
	}
}

pid_t	read_pid(char *pid_str)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (!pid_str || *pid_str == '\0')
	{
		ft_printf("Invalid server PID format\n");
		exit(1);
	}
	while (pid_str[i] != '\0')
	{
		if (!ft_isdigit(pid_str[i]))
		{
			ft_printf("Invalid server PID format\n");
			exit(1);
		}
		i++;
	}
	server_pid = ft_atoi(pid_str);
	if (server_pid <= 0)
	{
		ft_printf("Invalid server PID\n");
		exit(1);
	}
	return (server_pid);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*message;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = read_pid(argv[1]);
	message = argv[2];
	sa.sa_handler = handle_ack;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error setting up signal handler", 32);
		return (1);
	}
	send_len(server_pid, ft_strlen(message));
	while (*message)
		send_char(server_pid, *message++);
	send_char(server_pid, '\0');
	ft_printf("Message recived by server!\n");
	return (0);
}
