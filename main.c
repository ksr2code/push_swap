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
	if(check_arg(av))
		return (exit_error(NULL, NULL));
	stack_b = NULL;
	stack_a = get_stack_values(ac, av);
	s_size = get_stack_size(stack_a);
	set_index(stack_a, s_size);
	push_swap(&stack_a, &stack_b, stack_size, flag);
	free_stack(&stack_a, stack_b);
	return (0);
}
