#include <stddef.h>

void insertion_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    for(size_t i = 0; i < n; i++) {
        int key = arr[i];
        size_t j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
