#include <stdio.h>
#include <cstdlib>
using namespace std;

void	swap_heap(int *h1, int *h2)
{
	int		tmp;

	tmp = *h1;
	*h1 = *h2;
	*h2 = tmp;
}

int	delete_heap(int *arr, int *len)
{
	int		return_value;
	int		parent = 1;
	int		child = parent * 2;

	if (*len == 0)
		return 0;

	return_value = arr[parent];
	arr[parent] = arr[*len];
	arr[*len] = 0;
	*len -= 1;

	while (child <= *len) {
		if (child < *len) {
			if (abs(arr[child]) > abs(arr[child+1])) {
				++child;
			}
			else if (abs(arr[child]) == abs(arr[child+1]) && arr[child+1] < 0) {
				++child;
			}
		}

		if (abs(arr[parent]) > abs(arr[child])){
			swap_heap(&arr[parent], &arr[child]);
		}
		else if (abs(arr[parent]) == abs(arr[child]) && arr[child] < 0) {
			swap_heap(&arr[parent], &arr[child]);
		}
		else
			break;
		parent = child;
		child = parent * 2;
	}
	return return_value;
}

void	add_heap(int *arr, int x, int *len)
{
	int		parent;
	int		child;

	*len += 1;
	arr[*len] = x;
	child = *len;
	parent = child / 2;
	while (parent > 0) {
		if (abs(arr[child]) < abs(arr[parent])) {
			swap_heap(&arr[child], &arr[parent]);
		}
		else if (abs(arr[child]) == abs(arr[parent]) && arr[child] < 0) {
			swap_heap(&arr[child], &arr[parent]);
		}
		else
			break;
		child = parent;
		parent /= 2; 
	}
}

int	main(void)
{
	int		arr[100001] = {0, };
	int		n;
	int		x;
	int		heap_len = 0;
	int		num;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			num = delete_heap(arr, &heap_len);
			printf("%d\n", num);
		}
		else {
			add_heap(arr, x, &heap_len);
		}
	}
	return 0;
}
