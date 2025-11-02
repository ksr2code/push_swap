/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:14:34 by ksmailov          #+#    #+#             */
/*   Updated: 2025/11/02 13:16:48 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	have_duplicates(char **av, int flag)
{
	int	i;
	int	j;

	i = 1;
	if (flag)
		i++;
	while (av[i + 1])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_len(char *str)
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

int	valid_input(char **av, int flag)
{
	int	i;

	i = 0;
	if (flag)
		i++;
	while (av[++i])
		if (!is_number(av[i]) || !valid_len(av[i]))
			return (0);
	if (have_duplicates(av, flag))
		return (0);
	return (1);
}
