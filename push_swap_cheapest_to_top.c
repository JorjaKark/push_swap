/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cheapest_to_top.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:44:55 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 02:44:57 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operations_to_top(t_stack **stack, t_stack *node)
{
	int	position;
	int	stack_size;
	int	count;

	if (node == NULL || *stack == NULL)
		return (-1);
	if (stack == NULL)
		return (-1);
	position = get_position(*stack, node);
	stack_size = count_stack_size(*stack);
	count = 0;
	if (position == -1)
		return (-1);
	if (position == 0)
		return (count);
	if (position <= stack_size / 2)
		count = position;
	else
		count = stack_size - position;
	return (count);
}

void	push_costs(t_stack **stack, t_stack **other)
{
	t_stack	*current;
	int		cost;
	t_stack	*current_other;

	current = *stack;
	while (current != NULL)
	{
		cost = operations_to_top(stack, current);
		current->push_cost = cost;
		current = current->next;
	}
	current = *stack;
	while (current != NULL)
	{
		current_other = *other;
		while (current_other != (current)->target_node
			&& current_other != NULL)
			current_other = current_other->next;
		if (current_other != NULL)
		{
			cost = operations_to_top(other, current_other);
			current->push_cost += cost;
		}
		current = current->next;
	}
}

t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*cheapest_node;

	current = *stack;
	cheapest_node = NULL;
	if (current == NULL)
		return (NULL);
	cheapest_node = current;
	while (current != NULL)
	{
		if (cheapest_node->push_cost > current->push_cost)
			cheapest_node = current;
		current = current->next;
	}
	return (cheapest_node);
}

void	bring_to_top(t_stack **stack, t_stack *node)
{
	int	position;
	int	stack_size;

	if (node == NULL || *stack == NULL)
		return ;
	position = get_position(*stack, node);
	stack_size = count_stack_size(*stack);
	if (position == -1 || position == 0)
		return ;
	if (position <= stack_size / 2)
	{
		while (position > 0)
		{
			ra(stack);
			position = get_position(*stack, node);
		}
	}
	else
	{
		while (position > 0)
		{
			rra(stack);
			position = get_position(*stack, node);
		}
	}
}

void	bring_to_top_b(t_stack **stack, t_stack *node)
{
	int	position;
	int	stack_size;

	if (node == NULL || *stack == NULL)
		return ;
	position = get_position(*stack, node);
	stack_size = count_stack_size(*stack);
	if (position == -1 || position == 0)
		return ;
	if (position <= stack_size / 2)
	{
		while (position > 0)
		{
			rb(stack);
			position = get_position(*stack, node);
		}
	}
	else
	{
		while (position > 0)
		{
			rrb(stack);
			position = get_position(*stack, node);
		}
	}
}
