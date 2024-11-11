/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:48:37 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/26 06:22:12 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_lastnode(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*create_stack(char **stack_array)
{
	auto t_stack * stack = NULL;
	auto t_stack * new_node = NULL;
	auto t_stack * last_node = NULL;
	auto int i = 0;
	auto int nbr = 0;
	while (stack_array[i])
	{
		nbr = ft_atol(stack_array[i++]);
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nbr = nbr;
		new_node->next = NULL;
		if (stack == NULL)
			stack = new_node;
		else
		{
			last_node = find_lastnode(stack);
			last_node->next = new_node;
		}
	}
	return (stack);
}

char	**help_main(int argc, char **argv)
{
	auto char **stack_array = NULL;
	auto int i = 1;
	auto int j = 0;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		stack_array = ft_split(argv[1], ' ');
	if (!stack_array && argc == 2)
		return (NULL);
	else if (argc == 2 && !is_valid_array(stack_array))
	{
		free_array(stack_array);
		return (NULL);
	}
	else if (argc > 2)
	{
		stack_array = (char **)malloc((argc) * sizeof(char *));
		while (argv[i])
			stack_array[j++] = ft_strdup(argv[i++]);
		stack_array[j] = NULL;
	}
	return (stack_array);
}

long	ft_atol(const char *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = result * 10 + (nbr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	char	**stack_array;
	t_stack	*a;

	a = NULL;
	stack_array = help_main(argc, argv);
	if (stack_array == NULL)
		return (0);
	else if (argc > 2 && !is_valid_array(stack_array))
	{
		free_array(stack_array);
		return (0);
	}
	a = create_stack(stack_array);
	free_array(stack_array);
	if (check_duplicates(a) || check_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	call_sizes(&a);
	free_stack(a);
	return (0);
}
