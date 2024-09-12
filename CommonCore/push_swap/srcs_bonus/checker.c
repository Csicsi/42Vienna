/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:15:32 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/07/18 13:20:59 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (1);
}

static int	execute_instruction(const char *instr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		sa_bonus(a);
	else if (ft_strcmp(instr, "sb\n") == 0)
		sb_bonus(b);
	else if (ft_strcmp(instr, "ss\n") == 0)
		ss_bonus(a, b);
	else if (ft_strcmp(instr, "pa\n") == 0)
		pa_bonus(a, b);
	else if (ft_strcmp(instr, "pb\n") == 0)
		pb_bonus(a, b);
	else if (ft_strcmp(instr, "ra\n") == 0)
		ra_bonus(a);
	else if (ft_strcmp(instr, "rb\n") == 0)
		rb_bonus(b);
	else if (ft_strcmp(instr, "rr\n") == 0)
		rr_bonus(a, b);
	else if (ft_strcmp(instr, "rra\n") == 0)
		rra_bonus(a);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		rrb_bonus(b);
	else if (ft_strcmp(instr, "rrr\n") == 0)
		rrr_bonus(a, b);
	else
		return (operation_error(a, b));
	return (0);
}

static int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size < 2)
		return (1);
	current = stack->head;
	while (current->next != stack->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		error;

	line = get_next_line(0);
	while (line != NULL)
	{
		error = execute_instruction(line, a, b);
		free(line);
		if (error)
		{
			line = get_next_line(-1);
			write(2, "Error\n", 6);
			return (1);
		}
		line = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!initialize(argc, argv, &a, &b))
		return (write(2, "Error\n", 6));
	if (has_duplicates(a))
		return (write(2, "Error\n", 6), free_stack(a),
			free_stack(b), free(a), free(b), 1);
	if (process_instructions(a, b))
		return (1);
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(a), free_stack(b), free(a), free(b), 0);
}
