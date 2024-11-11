/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:31:55 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 02:31:57 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	pb(a, b);
	pb(a, b);
	while (count_stack_size(*a) > 3)
	{
		targets_first(a, b);
		push_costs(a, b);
		cheapest_node = find_cheapest(a);
		bring_to_top(a, cheapest_node);
		bring_to_top_b(b, cheapest_node->target_node);
		pb(a, b);
	}
	if (count_stack_size(*a) == 3)
		stack_three(a);
	push_back_to_a(a, b);
	return ;
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*min_node;

	if (a == NULL || b == NULL || *a == NULL || *b == NULL)
		return ;
	current = *a;
	while (count_stack_size(*b) > 0)
	{
		targets_second(a, b);
		if (*b == NULL || (*b)->target_node == NULL)
			return ;
		while (current != NULL && (*b)->target_node->nbr != current->nbr)
			current = current->next;
		if (current == NULL)
			return ;
		bring_to_top(a, current);
		pa(a, b);
		current = *a;
	}
	min_node = find_min(*a);
	if (min_node == NULL)
		return ;
	bring_to_top(a, min_node);
}

void	stack_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	help_three(a, first, second, third);
}

void	help_three(t_stack **a, t_stack *first, t_stack *second, t_stack *third)
{
	if (first->nbr < second->nbr && second->nbr < third->nbr)
		return ;
	if (first->nbr < third->nbr && second->nbr > third->nbr
		&& first->nbr < second->nbr)
	{
		sa(a);
		ra(a);
	}
	else if (first->nbr > second->nbr && second->nbr < third->nbr
		&& first->nbr < third->nbr)
		sa(a);
	else if (first->nbr < second->nbr && second->nbr > third->nbr
		&& first->nbr > third->nbr)
		rra(a);
	else if (first->nbr > second->nbr && second->nbr < third->nbr
		&& first->nbr > third->nbr)
		ra(a);
	else if (first->nbr > second->nbr && second->nbr > third->nbr)
	{
		sa(a);
		rra(a);
	}
}

void	call_sizes(t_stack **a)
{
	t_stack	*b;

	if (count_stack_size(*a) == 0)
		return ;
	else if (count_stack_size(*a) == 1)
		return ;
	else if (count_stack_size(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		return ;
	}
	else if (count_stack_size(*a) == 3)
	{
		stack_three(a);
		return ;
	}
	b = NULL;
	push_to_b(a, &b);
}
