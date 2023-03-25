/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/25 22:48:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "push_swap.h"

void	init_chank_b(t_data *data, int n)
{
	int	i;

	i = 0;
	data->chunk = ft_calloc(n, sizeof(int *));
	while (i < n)
	{
		data->chunk[i] = ft_calloc(3, sizeof(int));
		i++;
	}
}

void static	chunk_b(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
		{
			data->chunk[n - 1][START] = (i)*data->size / n;
			data->chunk[n - 1][END] = data->size;
			data->chunk[i][MIDDLE] = (data->chunk[i][START]
					+ data->chunk[i][END]) / 2;
		}
		else
		{
			data->chunk[i][START] = (i) * (data->size / n);
			data->chunk[i][END] = (i + 1) * (data->size / n);
			data->chunk[i][MIDDLE] = (data->chunk[i][START]
					+ data->chunk[i][END]) / 2;
		}
		i++;
	}
}

void static	sort_chunk_b(t_stack **a, t_stack **b, t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		while (ctrl_pb(data->tp, data->chunk[i][START], data->chunk[i][END]
				- 1))
		{
			if (((*a)->index <= data->chunk[i][END]))
			{
				switch_tp(data->tp, (*a)->index - 1, ON);
				pa_pb(a, b, PB);
				if (((*b)->index <= data->chunk[i][MIDDLE]))
					ra_rb(b, RB);
			}
			if ((*a))
				if (((*a)->index > data->chunk[i][END]))
					ra_rb(a, RA);
		}
		i++;
	}
}

void	push_biggest(t_stack **a, t_stack **b, t_data *data)
{
	init_chank_b(data, 6);
	chunk_b(data, 6);
	ft_bzero(data->tp, data->size * sizeof(int));
	sort_chunk_b(a, b, data, 6);
}