#include "pushswap.h"

static void	swap(int *arr, int a, int b)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static void	quickSort(int *arr, int	start, int end) // pivot 중앙값 찾기 등 나중에 더 알아보기
{
	int	pivot;
	int	left;
	int right;
	int n;

	if (start >= end) // 재귀 종료
		return ;
	pivot = end;
	left = start;
	right = pivot - 1;
	n = end + 1;
	while (left <= right) // left와 right 역전이 일어나기 전까지 반복
	{
		while (left < end && arr[left] < arr[pivot]) // 시작점부터 끝점까지 pivot보다 큰 것이 나올 때 까지 탐색
			left++;
		while (right >= start && arr[right] > arr[pivot]) // 끝점부터 시작점까지 pivot보다 작은 것이 나올 때 까지 탐색
			right--;
		if (left < right) // left와 right 역전 전 left와 right를 스왑
			swap(arr, left, right);
		else if (left != pivot && left > right) // left가 pivot이 아니고, left와 right가 같거나 역전 된 경우 pivot과 left를 스왑 (pivot보다 left가 크기 때문에)
			swap(arr, left, pivot);
	}
	quickSort(arr, start, right); // 기존 pivot 기준 left
	quickSort(arr, left + 1, end); // 기존 pivot 기준 right
}

void	sort_arr(t_arr_stack *stack, int *sort)
{
	int	i;
	int	j;

	i = -1;
	j = stack->front;
	while (++i < stack->cur_count)
	{
		sort[i] = stack->element[j].data;
		j = (j + 1) % stack->max_count;
	}
	quickSort(sort, 0, stack->cur_count - 1);
}