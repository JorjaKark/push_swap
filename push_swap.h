/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:55:55 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:55:57 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*target_node;
	int				push_cost;
}					t_stack;

// push_swap_algorithm.c
void				push_back_to_a(t_stack **a, t_stack **b);
void				push_to_b(t_stack **a, t_stack **b);
void				call_sizes(t_stack **a);
void				stack_three(t_stack **a);
void				help_three(t_stack **a, t_stack *first, t_stack *second,
						t_stack *third);

// push_swap_cheapest_to_top.c
int					operations_to_top(t_stack **stack, t_stack *node);
void				bring_to_top(t_stack **stack, t_stack *node);
void				push_costs(t_stack **stack, t_stack **other);
t_stack				*find_cheapest(t_stack **stack);
void				bring_to_top_b(t_stack **stack, t_stack *node);

// push_swap_checkers.c
int					check_duplicates(t_stack *stack);
int					is_valid_number(const char *str);
int					is_valid_array(char **stack_array);
int					check_sorted(t_stack *a);

// push_swap_back_to_a_utils.c
t_stack				*find_closest_bigger(t_stack *a, t_stack *b);
void				targets_second(t_stack **a, t_stack **b);
t_stack				*find_min(t_stack *stack);

// push_swap_both_utils.c
int					count_stack_size(t_stack *stack);
int					get_position(t_stack *stack, t_stack *node);
void				free_stack(t_stack *stack);
void				free_array(char **array);

// push_swap_to_b_utils.c
void				targets_first(t_stack **a, t_stack **b);
t_stack				*find_closest_smaller(t_stack *a, t_stack *b);
t_stack				*find_max(t_stack *stack);

// push_swap_push.c
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

// push_swap_reverse_rot.c
void				rra(t_stack **a);
void				rrb(t_stack **b);

// push_swap_rotate.c
void				ra(t_stack **a);
void				rb(t_stack **b);

// push_swap_swap.c
void				sa(t_stack **a);
void				sb(t_stack **b);

// push_swap.c
char				**help_main(int argc, char **argv);
t_stack				*find_lastnode(t_stack *stack);
t_stack				*create_stack(char **stack_array);
long				ft_atol(const char *nbr);

#endif
