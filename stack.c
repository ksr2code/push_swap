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

t_stack	*get_stack_values(int ac, char **av, int flag)
{
	int		i;
	long	nb;
	t_stack *stack_a;
	
	i = 1;
	if (flag)
		i++;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX && nb < INT_MIN)
			return (exit_error(stack_a, NULL), NULL);
		if(!stack_a)
			stack_a = stack_new((int)nb);
	}
}
