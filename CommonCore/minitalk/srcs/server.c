/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:46:38 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/18 09:16:53 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_length_signal(int sig, t_signal_state *state)
{
	if (sig == SIGUSR1)
		state->len |= (1 << (state->bit_len));
	(state->bit_len)++;
	if (state->bit_len == sizeof(size_t) * 8)
	{
		state->str = (char *)malloc(state->len + 1);
		if (!state->str)
		{
			write(2, "Memory allocation error\n", 24);
			exit(1);
		}
		state->str[state->len] = '\0';
		state->bit_len = 0;
		state->len_flag = 0;
	}
}

void	handle_char_signal(int sig, t_signal_state *state)
{
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << (state->bit));
	(state->bit)++;
	if (state->bit == 8)
	{
		state->str[state->str_index++] = c;
		if (state->str_index == state->len + 1)
		{
			write(1, state->str, state->len);
			write(1, "\n", 1);
			free(state->str);
			state->len = 0;
			state->bit_len = 0;
			state->bit = 0;
			state->len_flag = 1;
			state->str_index = 0;
		}
		c = 0;
		state->bit = 0;
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static t_signal_state	state = {0, 0, 0, 1, NULL, 0};
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (state.len_flag)
	{
		handle_length_signal(sig, &state);
		if (!state.len_flag)
			state.str_index = 0;
	}
	else
		handle_char_signal(sig, &state);
	if (kill(client_pid, SIGUSR1) == -1)
	{
		write(2, "Error sending signal\n", 22);
		if (state.str)
			free(state.str);
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
