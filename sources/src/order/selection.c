/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/21 11:45:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

int count_posicion(t_stack **a, int n)
{
	t_stack *tmp = *a;
	int i = 1;
	while (tmp)
	{
		if (tmp->index == n)
		{
			// printf(RED "%d: %d\n", (*a)->num, (*a)->index);
			break;
		}
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}

void movimiento(t_stack **a, int n)
{
	int i = 0;

	while (i < n)
	{
		ra_rb(a, RA);
		i++;
	}
}

void selection(t_stack **a, t_stack **b, int size)
{
	(void)b;

	if (size == 2)
		sa_sb(a, SA);
	else if (size == 3)
		sort_three(a);
	else if (size > 3 && size <= 5)
		sort_five(a, b, size);
	else if (size > 5 && size <= 100)
		sort_more(a, b, size);
	else
	{
		int i = 0;
		while (i < size)
		{
			movimiento(a, count_posicion(a, i));
			pa_pb(&(*a), &(*b), PB);
			i++;
		}
		i = 0;
		while (i < size)
		{
			pa_pb(&(*a), &(*b), PA);
			i++;
		}
	}
}
