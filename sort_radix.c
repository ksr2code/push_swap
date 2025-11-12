/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:15:29 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/13 00:33:24 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the highest set bit in an integer.
 *
 * @param n The integer to check.
 * @return  The position of the highest set bit.
 */
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
