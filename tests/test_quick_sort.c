#include "sorting.h"
#include "test_utils.h"

static void quick_sort_wrapper(int arr[], size_t n) {
    if (n > 0) {
        quick_sort(arr, 0, n - 1);
    }
}

int test_quick_sort(void) {
    return run_sort_test_cases("quick_sort", quick_sort_wrapper, 1);
}
