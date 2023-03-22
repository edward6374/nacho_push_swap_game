/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:29:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/22 19:17:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void sort_hundred(t_stack **a, t_stack **b, t_data *data)
{
	(void)a;
	(void)b;
	ft_bzero(data->tp, data->size * sizeof(int));
	// printf(RED "%d\n", first_inx(*b));
	switch_tp(data->tp, first_inx(*a), ON);
	switch_tp(data->tp, first_inx(*b), ON);
	switch_tp(data->tp, first_inx(*b), OFF);
	printf(YELLOW "act? %d\n", tp_is_act(data->tp, first_inx(*b)));

	print_tp(data);
}