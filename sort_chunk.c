/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:07 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/13 00:33:03 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Computes the integer square root of a number.
 *
 * @param nb The number to compute the square root for.
 * @return   The integer part of the square root of nb.
 */
static int	ft_sqrt(int nb)
{
	long	i;

	i = 0;
	if (nb < 1)
		return (0);
	while (i * i < (long)nb)
		i++;
	if (i * i == (long)nb)
		return (i);
	return ((int)i - 1);
}

/**
 * @brief Divides the stack into chunks and pushes them to stack_b.
 *
 * @param stack_a Pointer to the main stack.
 * @param stack_b Pointer to the auxiliary stack.
 * @param s_size  Number of elements in stack_a.
 * @param flag    Pointer to the flag structure for options and benchmarking.
 */
static void	make_chunks(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	i;
	int	s_chunk;

	i = 0;
	s_chunk = ft_sqrt(s_size) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			do_pb(stack_a, stack_b, flag);
			if (*stack_a && ((*stack_a)->index <= i || (*stack_a)->index <= i
					+ s_chunk))
				do_rb(stack_b, flag);
			else
				do_rr(stack_a, stack_b, flag);
			i++;
		}
		else if ((*stack_a)->index <= i + s_chunk)
		{
			do_pb(stack_a, stack_b, flag);
			i++;
		}
		else
			do_ra(stack_a, flag);
	}
}

/**
 * @brief Counts the number of rotations needed to bring the max index to top.
 *
 * @param stack   Pointer to the stack.
 * @param s_size  Number of elements in the stack.
 * @return        The number of rotations required.
 */
static int	count_r(t_stack *stack, int s_size)
{
	int	count;

	count = 0;
	while (stack && stack->index != (s_size - 1))
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	int	r_count;
	int	rr_count;

	make_chunks(stack_a, stack_b, s_size, flag);
	while (s_size - 1 >= 0)
	{
		r_count = count_r(*stack_b, s_size);
		rr_count = s_size - r_count;
		if (r_count <= rr_count)
		{
			while ((*stack_b)->index != s_size - 1)
				do_rb(stack_b, flag);
			do_pa(stack_a, stack_b, flag);
			s_size--;
		}
		else
		{
			while ((*stack_b)->index != s_size - 1)
				do_rrb(stack_b, flag);
			do_pa(stack_a, stack_b, flag);
			s_size--;
		}
	}
}
