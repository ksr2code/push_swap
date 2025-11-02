/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:38:56 by atvii             #+#    #+#             */
/*   Updated: 2025/11/02 15:33:01 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag flag)
{
	int	i;
	int	sorted;

	(void)flag;
	sorted = 0;
	while (sorted < s_size - 1)
	{
		i = 0;
		while (i < s_size - 1 - sorted)
		{
			if ((*stack_a)->index < (*stack_a)->next->index)
				do_sa(stack_a);
			do_ra(stack_a);
			i++;
		}
		do_pb(stack_a, stack_b);
		sorted++;
	}
	while (*stack_b)
		do_pa(stack_a, stack_b);
}
