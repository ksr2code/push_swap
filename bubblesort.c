/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:38:56 by atvii             #+#    #+#             */
/*   Updated: 2025/10/31 00:19:05 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack_a, int s_size)
{
	int i;
	int j;
	int swapped;

	if (!stack_a || !*stack_a || s_size < 2)
		return ;
	i = -1;
	while (++i < s_size - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < s_size - i - 1)
		{
			if ((*stack_a)->next
				&& (*stack_a)->index > (*stack_a)->next->index)
			{
				do_sa(stack_a);
				swapped = 1;
			}
			do_ra(stack_a);
		}
		j = -1;
		while (++j < s_size - i - 1)
			do_rra(stack_a);
		if (!swapped)
			break ;
	}
}
