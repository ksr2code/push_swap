/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:34 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/05 18:59:56 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] == '-' || av[i] == '+') && av[i + 1] != '\0')
			i++;
		if (!ft_isdigit(av[i]))
			return (0);
		while (ft_isdigit(av[i]) || av[i] == ' ')
			i++;
		if (av[i] != '\0')
			return (0);
	}
	return (1);
}

static int	have_duplicates(char **av, t_flag flag)
{
	t_stack	*head;
	t_stack	*ptr1;
	t_stack	*ptr2;

	head = get_stack_values(av, flag);
	if (!ft_stack_size(head))
		return (1);
	ptr1 = head;
	while (ptr1 && ptr1->next)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->value == ptr2->value)
				return (1);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	free_stack(&head);
	return (0);
}

static int	valid_len(char *str)
{
	int	len;
	int	zeros;

	len = 0;
	zeros = 0;
	if (str[len] == '-' || str[len] == '+')
		len++;
	while (str[len] && str[len] == '0')
	{
		zeros++;
		len++;
	}
	while (str[len] && ft_isdigit(str[len]))
		len++;
	if ((len - zeros) > 11)
		return (0);
	return (1);
}

int	valid_input(char **av, t_flag flag)
{
	int	i;

	i = 0;
	if (flag.type)
		i++;
	if (flag.bench)
		i++;
	while (av[++i])
		if (!is_number(av[i]) || !valid_len(av[i]))
			return (0);
	if (have_duplicates(av, flag))
		return (0);
	return (1);
}
