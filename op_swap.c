/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:15:00 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/02 13:15:10 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	do_sa(t_stack **stack_a, t_flag *flag)
{
	swap(stack_a);
	if (!flag->bench)
		ft_putstr_fd("sa\n", 1);
	flag->sa++;
}

void	do_sb(t_stack **stack_b, t_flag *flag)
{
	swap(stack_b);
	if (!flag->bench)
		ft_putstr_fd("sb\n", 1);
	flag->sb++;
}
