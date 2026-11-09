#include <stddef.h>

void swap(int *a, int *b) {
    if(!a || !b) return;
    int t = *a;
    *a = *b;
    *b = t;
}

size_t partition(int arr[], size_t low, size_t high) {
    if(!arr) return 0;
    if(low <= 1 || high <= 1) return 0;

    size_t pivot = arr[high];
    size_t i = (low - 1);

    for(size_t j = low; j <= high - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], size_t low, size_t high) {
    if(!arr) return;
    if(low <= 1 || high <= 1) return;

    if(low < high) {
        size_t pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
