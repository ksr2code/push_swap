/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:07 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/02 15:33:17 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// static int	calc_chunk(int s_size)
// {
// 	int	s_chunk;
//
// 	if (s_size <= 100)
// 		s_chunk = s_size / 6;
// 	else
// 		s_chunk = ft_sqrt(s_size) * 125 / 100;
// 	if (s_chunk < 3)
// 		s_chunk = 3;
// 	return (s_chunk);
// }

static void	make_chunks(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	int	i;
	int	s_chunk;

	i = 0;
	s_chunk = ft_sqrt(s_size) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			do_pb(stack_a, stack_b);
			do_rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + s_chunk)
		{
			do_pb(stack_a, stack_b);
			i++;
		}
		else
			do_ra(stack_a);
	}
}

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
		t_flag flag)
{
	int	r_count;
	int	rr_count;

	(void)flag;
	make_chunks(stack_a, stack_b, s_size);
	while (s_size - 1 >= 0)
	{
		r_count = count_r(*stack_b, s_size);
		rr_count = s_size - r_count;
		if (r_count <= rr_count)
		{
			while ((*stack_b)->index != s_size - 1)
				do_rb(stack_b);
			do_pa(stack_a, stack_b);
			s_size--;
		}
		else
		{
			while ((*stack_b)->index != s_size - 1)
				do_rrb(stack_b);
			do_pa(stack_a, stack_b);
			s_size--;
		}
	}
}
