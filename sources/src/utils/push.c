/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:39:48 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/09 12:30:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

// añade valores al stack
void push(int *stack, int *top, int value, int size)
{
	if (*top >= size - 1)
	{
		ft_message(DANGER, ERROR_4);
		exit(1);
	}
	*top = *top + 1;
	stack[*top] = value;
}

int pop(t_ps *stack, int *top)
{
	int value;

	if (stack->top == -1)
	{
		ft_message(DANGER, ERROR_5);
		exit(1);
	}
	value = stack->stack[*top];
	*top = *top - 1;
	return value;
}

// //  toma el primer elemento del stack b y lo pone encima del stack a.
// // No hace nada si b está vacío.
// void pa(t_data *data)
// {
// 	if (top_b >= 0)
// 	{
// 		int value;

// 		value = pop(stack_b, &top_b);
// 		push(stack_a, &top_a, value);
// 	}
// }

// toma el primer elemento del stack a y lo pone encima del stack b.
// No hace nada si a está vacío.
void pb(t_data *data)
{
	if (data->a.top >= 0)
	{
		push(data->b.stack, &data->b.top, data->a.stack[0], data->size);
		// data->a.top -= 1;
	}
}
