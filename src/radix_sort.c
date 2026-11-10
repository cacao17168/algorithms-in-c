#include <stddef.h>

int get_max(int arr[], size_t n) {
    if(!arr) return 0;
    int mx = arr[0];
    for(size_t i = 1; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void count_sort(int arr[], size_t n, size_t exp) {
    if(!arr) return;

    int output[n];
    int count[10] = {0};

    for(size_t i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for(size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(size_t i = n; i > 0; i--) {
        int val = arr[i - 1];
        int d = (val / exp) % 10;
        output[count[d] - 1] = val;
        count[d]--;
    }

    for(size_t i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    int m = get_max(arr, n);
    if(m < 0) return;

    for(size_t exp = 1; m / exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}
