/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/01 15:08:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../libft/inc/get_next_line.h"
#include "push_swap_bonus.h"

void	print_lst(t_stack *num)
{
	while (num)
	{
		printf(CYAN "%d \n", num->num);
		num = num->next;
	}
}

// t_stack	*tmp_stack_b(int arr[], int size)
// {
// 	int		i;
// 	t_stack	*aux;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (i == 0)
// 			aux = stack_new(arr[i]);
// 		else
// 			stackadd_back(&aux, stack_new(arr[i]));
// 		i++;
// 	}
// 	return (aux);
// }

void	filter(t_stack **a, t_stack **b, char *order)
{
	if (!ft_strncmp(order, "sa\n", 3))
		sa_sb(a);
	else if (!ft_strncmp(order, "sb\n", 3))
		sa_sb(b);
	else if (!ft_strncmp(order, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(order, "pa\n", 3))
		pa_pb(a, b, PA);
	else if (!ft_strncmp(order, "pb\n", 3))
		pa_pb(a, b, PB);
	else if (!ft_strncmp(order, "ra\n", 3))
		ra_rb(a);
	else if (!ft_strncmp(order, "rb\n", 3))
		ra_rb(b);
	else if (!ft_strncmp(order, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(order, "rra\n", 3))
		rra_rrb(a);
	else if (!ft_strncmp(order, "rrb\n", 3))
		rra_rrb(b);
	else if (!ft_strncmp(order, "rrr\n", 3))
		rrr(a, b);
	else
		ctrl_order(a, b);
}

void	get_line(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		filter(a, b, line);
		if (line)
			free(line);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	*stack_a;
	t_stack	*stack_b;

	// int		b[3];
	ctrl_num(argc - 1, argv);
	init_data(&data, argc - 1);
	stack_a = add_num(&data, argv);
	ctrl_num_dupl(&data);
	ctrl_sorted(&data);
	stack_b = NULL;
	get_line(&stack_a, &stack_b);
	ctrl_sorted_user(stack_a);
	//=====add num tmp to B=============================================================
	// b[0] = 30;
	// b[1] = 20;
	// b[2] = 10;
	// stack_b = tmp_stack_b(b, 3);
	//=========================================================================
	// ss(&stack_a, &stack_b);
	// sa_sb(&stack_a);
	// sa_sb(&stack_b);
	// rr(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	//=========================================================================
	printf(GREEN "----A----\n");
	print_lst(stack_a);
	printf(GREEN "----B----\n");
	print_lst(stack_b);
	//=========================================================================
	return (0);
}
