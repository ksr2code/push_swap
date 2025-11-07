/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:34:29 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/07 11:27:53 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int s_size,
		t_flag *flag)
{
	flag->disorder = compute_disorder(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if (flag->type == 1)
		low_disorder_sort(stack_a, stack_b, s_size, flag);
	else if (flag->type == 2)
		radix_sort(stack_a, stack_b, s_size, flag);
	else if (flag->type == 3)
		chunk_sort(stack_a, stack_b, s_size, flag);
	else if (flag->disorder < 0.2)
		low_disorder_sort(stack_a, stack_b, s_size, flag);
	else
		chunk_sort(stack_a, stack_b, s_size, flag);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;
	t_flag	flag;

	if (ac < 2)
		return (0);
	parse_flags(av, &flag);
	if (!valid_input(av, flag))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = get_stack_values(av, flag);
	if (!stack_a)
		return (0);
	s_size = ft_stack_size(stack_a);
	set_index(stack_a, s_size);
	push_swap(&stack_a, &stack_b, s_size, &flag);
	if (flag.bench)
		print_bench(flag);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
