/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:15:29 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/02 15:33:40 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_bit(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = highest_bit(s_size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < s_size)
		{
			if (((*stack_a)->index >> i) & 1)
				do_ra(stack_a, flag);
			else
				do_pb(stack_a, stack_b, flag);
			j++;
		}
		while (*stack_b)
			do_pa(stack_a, stack_b, flag);
		i++;
	}
}
