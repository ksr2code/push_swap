/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annaviktorova <annaviktorova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:16:11 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/08 19:22:06 by annaviktoro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_bench(t_flag flag)
{
	ft_printf("[bench] disorder: %i.%i%%\n", (int)(flag.disorder * 100),
		(int)((flag.disorder - (int)flag.disorder) * 100));
	if (flag.type == 1)
		ft_printf("[bench] strategy: Simple / O(n²)\n");
	else if (flag.type == 2)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (flag.type == 3)
		ft_printf("[bench] strategy: Complex / O(nlogn)\n");
	else if (flag.disorder < 0.2)
		ft_printf("[bench] strategy: Adaptive / O(n)\n");
	else if (flag.disorder >= 0.2 && flag.disorder < 0.5)
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
	else if (flag.disorder >= 0.5)
		ft_printf("[bench] strategy: Adaptive / O(nlogn)\n");
	ft_printf("[bench] total_ops: %i\n", (flag.sb + flag.sa + flag.ss + flag.pa
			+ flag.pb + flag.ra + flag.rb + flag.rr + flag.rra + flag.rrb
			+ flag.rrr));
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb:% i\n", flag.sa, flag.sb,
		flag.ss, flag.pa, flag.pb);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb:% i rrr: %i\n", flag.ra,
		flag.rb, flag.rr, flag.rra, flag.rrb, flag.rrr);
}
