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

static void	sort_arr(arr_stack *a, int *sort)
{
	int	i;

	i = -1;
	while (++i < a->max_count)
		sort[i] = a->element[i].data;
	quickSort(sort, 0, a->max_count - 1);
	a->min = sort[0];
	a->max = sort[a->max_count - 1];
	i = -1;
}

void a_to_b(arr_stack *a, arr_stack *b, int count, int pivot1, int pivot2) // ㅋㅟㄱ 소트로 매번 정렬을 만들어야 함 인덱스 계산 도무지 어디를 엔드점으로 줘야 하는 지 모르겠음 개  빡빡침  
{
	int i;
	int j;

	i = -1;
	j = a->cur_count;
	while (++i < j)
	{
		if (a->element[a->front].data >= pivot1)
			ft_ra_rb(a, 1);
		else
		{
			ft_pa_pb(a, b, 2);
			if (b->element[b->front].data >= pivot2)
				ft_ra_rb(b, 2);
		}
	}
	while (a->ra-- > 0 && b->rb-- > 0) // ra rb를 훼손을 안하고 어케함 ??? 어이없음... 이걸 변수를 또 저장하라고..?
		ft_rrr(a, b);
	while (a->ra-- >= 0)
		ft_rra_rrb(a, 1);
	while (b->rb-- >= 0)
		ft_rra_rrb(b, 2);
	
}


// void b_to_a(arr_stack *a, arr_stack *b, int *sort, int pivot1, int pivot2)
// {
// 	int i;

// 	i = -1;
// 	while (++i < b->cur_count)
// 	{
// 		if (b->element[])
// 	}
// }

void push_swap(arr_stack *a, arr_stack *b)
{
	int sort[a->max_count];

	sort_arr(a, sort);
	printf("index1: %d, index2: %d\n", a->max_count / 3 * 2, a->max_count / 3);
	a_to_b(a, b, a->cur_count, sort[a->max_count / 3 * 2], sort[a->max_count / 3]);
	print_arr(a, 1);
	print_arr(b, 2);
}