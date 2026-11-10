#include <stddef.h>
#include <stdio.h>

#include "sorting.h"

static void print_array(const char *label, const int arr[], size_t n) {
    printf("%s: [", label);
    for (size_t i = 0; i < n; i++) {
        printf("%d%s", arr[i], i + 1 < n ? ", " : "");
    }
    printf("]\n");
}

int main(void) {
    int a1[] = {5, 2, 9, 1, 5, 6};
    size_t n1 = sizeof(a1) / sizeof(a1[0]);
    bubble_sort(a1, n1);
    print_array("bubble_sort", a1, n1);

    int a2[] = {4, 2, 7, 1, 4};
    size_t n2 = sizeof(a2) / sizeof(a2[0]);
    selection_sort(a2, n2);
    print_array("selection_sort", a2, n2);

    int a3[] = {9, 3, 7, 1, 8, 2};
    size_t n3 = sizeof(a3) / sizeof(a3[0]);
    shell_sort(a3, n3);
    print_array("shell_sort", a3, n3);

    int a4[] = {4, 2, 2, 8, 3, 3, 1};
    size_t n4 = sizeof(a4) / sizeof(a4[0]);
    counting_sort(a4, n4);
    print_array("counting_sort (non-negative)", a4, n4);

    int a5[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size_t n5 = sizeof(a5) / sizeof(a5[0]);
    radix_sort(a5, n5);
    print_array("radix_sort (non-negative)", a5, n5);

    int a6[] = {0, 0, 0, 0};
    size_t n6 = sizeof(a6) / sizeof(a6[0]);
    bucket_sort(a6, n6);
    print_array("bucket_sort (zeros, current impl)", a6, n6);

    int a7[] = {4, 2, 7, 1, 3};
    size_t n7 = sizeof(a7) / sizeof(a7[0]);
    if (n7 > 0) {
        merge_sort(a7, 0, n7 - 1);
    }
    print_array("merge_sort", a7, n7);

    int a8[] = {4, 2, 7, 1, 3};
    size_t n8 = sizeof(a8) / sizeof(a8[0]);
    if (n8 > 0) {
        quick_sort(a8, 0, n8 - 1);
    }
    print_array("quick_sort", a8, n8);

    int a9[] = {4, 2, 7, 1, 3};
    size_t n9 = sizeof(a9) / sizeof(a9[0]);
    heap_sort(a9, n9);
    print_array("heap_sort", a9, n9);

    int a10[] = {4, 2, 7, 1, 3};
    size_t n10 = sizeof(a10) / sizeof(a10[0]);
    insertion_sort(a10, n10);
    print_array("insertion_sort", a10, n10);

    return 0;
}
