/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:53:03 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/05 23:01:18 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*ptr;

	mistakes = 0;
	total_pairs = 0;
	while (stack && stack->next)
	{
		ptr = stack->next;
		while (ptr)
		{
			total_pairs++;
			if (stack->index > ptr->index)
				mistakes++;
			ptr = ptr->next;
		}
		stack = stack->next;
	}
	if (!total_pairs)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

static void	init_flags(t_flag *flag)
{
	flag->type = 0;
	flag->bench = 0;
	flag->sa = 0;
	flag->sb = 0;
	flag->ss = 0;
	flag->pa = 0;
	flag->pb = 0;
	flag->ra = 0;
	flag->rb = 0;
	flag->rr = 0;
	flag->rra = 0;
	flag->rrb = 0;
	flag->rrr = 0;
	flag->disorder = 0.0f;
}

static int	is_flag(char *arg, t_flag *flag)
{
	if (!arg || arg[0] != '-' || arg[1] != '-')
		return (0);
	if (ft_strcmp(arg, "--bench") == 0)
		flag->bench = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		flag->type = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		flag->type = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		flag->type = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		flag->type = 4;
	else
		return (0);
	return (1);
}

void	parse_flags(char **av, t_flag *flag)
{
	int	i;

	i = 1;
	init_flags(flag);
	while (av && av[i] && is_flag(av[i], flag))
		i++;
}
