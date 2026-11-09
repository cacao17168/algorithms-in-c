#include <stddef.h>

void shell_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    for(size_t gap = n / 2; gap > 0; gap /= 2) {
        for(size_t i = gap; i < n; i++) {
            int temp = arr[i];
            size_t j;

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
