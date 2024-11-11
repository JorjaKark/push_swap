/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:09:32 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:09:35 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	top_b = *b;
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	top_b->next = *a;
	*a = top_b;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	top_a = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	top_a->next = *b;
	*b = top_a;
	ft_printf("pb\n");
}
