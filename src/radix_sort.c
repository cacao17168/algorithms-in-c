#include <stddef.h>

int get_max(int arr[], size_t n) {
    if(!arr) return 0;
    if(n <= 1) return 0;

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
    if(n <= 1 || exp <= 1) return;

    int output[n];
    int count[10] = {0};

    for(size_t i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for(size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(size_t i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(size_t i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], size_t n) {
    if(!arr) return;
    if(n <= 1) return;

    size_t m = (size_t)get_max(arr, n);
    for(size_t exp = 1; m / exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}
