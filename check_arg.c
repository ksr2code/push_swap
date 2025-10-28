int is_number(char *av)
{
	int i;

	i = 0;
	while ((av[i] == '-' || av[i] == '+') && av[i + 1] != '\0')
		i++;
    while (av[i] && is_digit(av[i]))
        i++;
    if (av[i] != '\0')
        return (0);
    return (1);
}

int have_duplicates(char **av)
{
}

int	check_arg(char **av)
{
	int i;

	i = 0;
	while (av[++i])
		if (!is_number(av[i]))
			return (1);
	if (have_duplicates(av))
		return (1);
	return (0);
}
