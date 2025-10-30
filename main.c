/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:34:29 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/27 14:36:37 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	check_flags(char *av)
{
	if (ft_strcmp(av, "--simple") == 0)
		return (1);
	else if (ft_strcmp(av, "--medium") == 0)
		return (2);
	else if (ft_strcmp(av, "--complex") == 0)
		return (3);
	else if (ft_strcmp(av, "--adaptive") == 0)
		return (4);
	return (0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int s_size, int flag)
{
	(void)flag;
	if (is_sorted(*stack_a))
		exit_error(NULL, NULL);
	radix_sort(stack_a, stack_b, s_size);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;
	int		flag;

	if (ac < 2)
		return (0);
	flag = check_flags(av[1]);
	if (!valid_input(av, flag))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = get_stack_values(av, flag);
	s_size = ft_stack_size(stack_a);
	set_index(stack_a, s_size);
	push_swap(&stack_a, &stack_b, s_size, flag);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
