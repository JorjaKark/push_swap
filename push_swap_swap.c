/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:11:52 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 03:11:53 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// First Two Top Node
void	sa(t_stack **a)
{
	int	temp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	int	temp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = temp;
	ft_printf("sb\n");
}
