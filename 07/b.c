#include <stdio.h>
#include <stdbool.h>

void* min_element(void* arr, size_t nitems, size_t item_size, bool(*comp)(void*, void*)) {
	void* mn = NULL;
	for (size_t i = 0; i < nitems; ++i, arr += item_size) {
		if (mn == NULL || comp(arr, mn)) {
			mn = arr;
		}
	}
	return mn;
}

bool cmp(void* x, void* y) {
	return *(int*)x < *(int*)y;
}

int main() {
	int a[3] = {1, -2, 3};
	int mn = *(int*)min_element(a, 3, sizeof(a[0]), cmp);
	printf("%d\n", mn);
}