#include "push_swap.h"

int	is_number(char *av)
{
	int	i;

	i = 0;
	while ((av[i] == '-' || av[i] == '+') && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	nb_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
		s1++;
	if (*s2 == '+')
		s2++;
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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

int	check_arg(char **av, int flag)
{
	int	i;

	i = 0;
	if (flag)
		i++;
	while (av[++i])
		if (!is_number(av[i]))
			return (1);
	if (have_duplicates(av, flag))
		return (1);
	return (0);
}
