#include <stddef.h>
#include <stdlib.h>

void counting_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    int max = arr[0];
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    if(!count) return;

    for(size_t i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for(size_t i = 1; i <= (size_t)max; i++) {
        count[i] += count[i - 1];
    }

    int *output = (int *)malloc(n * sizeof(int));
    if(!output) {
        free(count);
        return;
    }

    for(size_t i = n - 1; i <= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(size_t i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(count);
}
