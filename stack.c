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

long	ft_atol(const char *str)
{
	long	res;
	long	neg;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nb;
	new->index = 0;
	new->next = NULL;
	return (new);
}

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
		if (!stack_a)
			stack_a = stack_new((int)nb);
		else
			ft_stackadd_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
