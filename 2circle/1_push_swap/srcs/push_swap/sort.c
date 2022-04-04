/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:04 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/04/04 08:44:39 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	left;
	int	right;
	int	n;

	if (start >= end)
		return ;
	pivot = end;
	left = start;
	right = pivot - 1;
	n = end + 1;
	while (left <= right)
	{
		while (left < end && arr[left] < arr[pivot])
			left++;
		while (right >= start && arr[right] > arr[pivot])
			right--;
		if (left < right)
			swap(arr, left, right);
		else if (left != pivot && left > right)
			swap(arr, left, pivot);
	}
	quick_sort(arr, start, right);
	quick_sort(arr, left + 1, end);
}

int	*sort_arr(t_stack *main, t_stack *sub, int count)
{
	int	*sort;
	int	i;
	int	j;

	sort = malloc(sizeof(int) * count);
	if (!sort)
		error_free(main, sub);
	i = -1;
	j = main->front;
	while (++i < count)
	{
		sort[i] = main->arr[j].data;
		j = (j + 1) % main->max_count;
	}
	quick_sort(sort, 0, count - 1);
	return (sort);
}
