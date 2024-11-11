/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_back_a_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:57:47 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 02:57:50 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_closest_bigger(t_stack *a, t_stack *b)
{
	t_stack	*closest;
	int		b_value;
	t_stack	*c;

	closest = NULL;
	b_value = b->nbr;
	c = a;
	while (c != NULL)
	{
		if (b_value < c->nbr && (closest == NULL || c->nbr < closest->nbr))
			closest = c;
		c = c->next;
	}
	if (closest == NULL)
		closest = find_min(a);
	return (closest);
}

void	targets_second(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *b;
	while (current != NULL)
	{
		current->target_node = find_closest_bigger(*a, current);
		current = current->next;
	}
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;

	current = stack;
	if (stack == NULL)
		return (NULL);
	min_node = stack;
	while (current != NULL)
	{
		if (current->nbr < min_node->nbr)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
