/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:50:04 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/02 14:50:48 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_a, int s_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--s_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = s_size;
	}
}

t_stack	*get_stack_values(char **av, t_flag flag)
{
	int		i;
	long	nb;
	t_stack	*stack_a;
	t_stack *tmp;

	i = 1;
	if (flag.type)
		i++;
	if (flag.bench)
		i++;
	stack_a = NULL;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		tmp = stack_new((int)nb);
		if (!tmp)
			exit_error(&stack_a, NULL);
		ft_stackadd_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}
