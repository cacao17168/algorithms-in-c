#include "sorting.h"
#include "test_utils.h"

static void merge_sort_wrapper(int arr[], size_t n) {
    if (n > 0) {
        merge_sort(arr, 0, n - 1);
    }
}

int test_merge_sort(void) {
    return run_sort_test_cases("merge_sort", merge_sort_wrapper, 1);
}
