/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:10:41 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:10:44 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Bottom -> Top
void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*current;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	prev = NULL;
	current = *a;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *a;
	*a = current;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*current;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	prev = NULL;
	current = *b;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *b;
	*b = current;
	ft_printf("rrb\n");
}
