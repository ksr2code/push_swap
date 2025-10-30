/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:34:21 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/27 14:35:37 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		valid_input(char **av, int flag);
t_stack	*get_stack_values(char **av, int flag);
void	set_index(t_stack *stack_a, int s_size);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
long	ft_atol(const char *str);

int		ft_stack_size(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int s_size);

void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
