/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_to_b_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:04:13 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:05:42 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_closest_smaller(t_stack *node, t_stack *other)
{
	t_stack	*closest;
	int		node_value;
	t_stack	*current_other;

	closest = NULL;
	node_value = node->nbr;
	current_other = other;
	while (current_other != NULL)
	{
		if (current_other->nbr < node_value && (closest == NULL
				|| current_other->nbr > closest->nbr))
		{
			closest = current_other;
		}
		current_other = current_other->next;
	}
	if (closest == NULL)
		closest = find_max(other);
	return (closest);
}

void	targets_first(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		current->target_node = find_closest_smaller(current, *b);
		current = current->next;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*max_node;

	current = stack;
	if (stack == NULL)
		return (NULL);
	max_node = stack;
	while (current != NULL)
	{
		if (current->nbr > max_node->nbr)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}
