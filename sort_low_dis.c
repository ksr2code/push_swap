/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_dis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:06:41 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/07 11:06:58 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_disorder_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	i;

	while (!is_sorted(*stack_a))
	{
		if (((*stack_a)->index + 1 != (*stack_a)->next->index)
			&& ((*stack_a)->next->index + 1 != (*stack_a)->next->next->index))
		{
			do_ra(stack_a, flag);
			do_pb(stack_a, stack_b, flag);
			i = s_size;
			while (--i && !(((*stack_b)->index + 1 == (*stack_a)->index)
					|| (((*stack_b)->index == s_size - 1)
						&& ((*stack_a)->index == 0))))
				do_ra(stack_a, flag);
			do_pa(stack_a, stack_b, flag);
		}
		else if (is_sorted(*stack_a))
			break ;
		else
			do_ra(stack_a, flag);
	}
}
