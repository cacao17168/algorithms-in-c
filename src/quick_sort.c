#include <stddef.h>

void quick_swap(int *a, int *b) {
    if(!a || !b) return;
    int t = *a;
    *a = *b;
    *b = t;
}

size_t partition(int arr[], size_t low, size_t high) {
    if(!arr) return 0;

    int pivot = arr[high];
    size_t i = low;

    for(size_t j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            quick_swap(&arr[i], &arr[j]);
            i++;
        }
    }
    quick_swap(&arr[i], &arr[high]);
    return i;
}

void quick_sort(int arr[], size_t low, size_t high) {
    if(!arr) return;
    if(low >= high) return;

    size_t pi = partition(arr, low, high);

    if(pi > low) quick_sort(arr, low, pi - 1);
    if(pi < high) quick_sort(arr, pi + 1, high);
}
