#include <stddef.h>

void insertion_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    for(size_t i = 1; i < n; i++) {
        int key = arr[i];
        size_t j = i;

        while(j >= 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
