#include <stddef.h>

void heap_swap(int *a, int *b) {
    if(!a || !b) return;
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], size_t n, size_t i) {
    if(!arr) return;
    if(n <= 1 || i <= 1) return;

    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if(left < n && arr[left] > largest) {
        largest = left;
    }
    if(right < n && arr[right] > largest) {
        largest = right;
    }

    if(largest != i) {
        heap_swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    for(size_t i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(size_t i = n; i > 0; i--) {
        heap_swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
