// #include <iostream>
#include <stdio.h>
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
		if (child < *len && arr[child] > arr[child+1]) {
			++child;
		}
		if (arr[parent] > arr[child]){
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
		if (arr[child] < arr[parent]) {
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

	// cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// cin >> x;
		scanf("%d", &x);
		if (x == 0) {
			// cout << delete_heap(arr, &heap_len) << '\n';
			num = delete_heap(arr, &heap_len);
			printf("%d\n", num);
		}
		else {
			add_heap(arr, x, &heap_len);
		}
	}
	return 0;
}
