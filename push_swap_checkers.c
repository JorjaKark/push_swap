/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:45:57 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 02:45:59 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_stack	*stack_i;

	while (stack)
	{
		stack_i = stack->next;
		while (stack_i)
		{
			if (stack_i->nbr == stack->nbr)
			{
				ft_printf("Error\n");
				return (1);
			}
			stack_i = stack_i->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	is_valid_number(const char *str)
{
	long	num;

	num = atol(str);
	if (*str == '\0')
		return (0);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_array(char **stack_array)
{
	int	i;

	i = 0;
	if (!stack_array)
	{
		return (0);
	}
	while (stack_array[i] != NULL)
	{
		if (!is_valid_number(stack_array[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sorted(t_stack *a)
{
	auto t_stack * current = a;
	if (current == NULL || current->next == NULL)
		return (1);
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}
