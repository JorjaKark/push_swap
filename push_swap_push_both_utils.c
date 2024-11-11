/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_both_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:59:58 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:00:08 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_size(t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	get_position(t_stack *stack, t_stack *node)
{
	int		position;
	t_stack	*current;

	position = 0;
	current = stack;
	if (node == NULL)
		return (-1);
	while (current != NULL)
	{
		if (current->nbr == node->nbr)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
