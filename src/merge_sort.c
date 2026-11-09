#include <stdlib.h>
#include <stddef.h>

void merge(int arr[], size_t left, size_t mid, size_t right) {
    if(!arr) return;
    if(left <= 0 || mid <= 0 || right <= 0) return;

    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = mid - right;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for(j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0; j = 0; k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], size_t left, size_t right) {
    if(!arr) return;
    if(left <= 0 || right <= 0) return;

    if(left < right) {
        size_t mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
