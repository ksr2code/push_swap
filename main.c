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

static int	check_flags(char *av)
{
	if (ft_strncmp(av, "--simple", 9) == 0)
		return (1);
	else if (ft_strncmp(av, "--medium", 9) == 0)
		return (2);
	else if (ft_strncmp(av, "--complex", 10) == 0)
		return (3);
	else if (ft_strncmp(av, "--adaptive", 11) == 0)
		return (4);
	return (0);
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
	if(check_arg(av, flag))
		return (exit_error(NULL, NULL));
	stack_b = NULL;
	stack_a = get_stack_values(ac, av, flag);
	s_size = get_stack_size(stack_a);
	set_index(stack_a, s_size);
	push_swap(&stack_a, &stack_b, stack_size, flag);
	free_stack(&stack_a, stack_b);
	return (0);
}
