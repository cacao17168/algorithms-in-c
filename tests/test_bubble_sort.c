#include "sorting.h"
#include "test_utils.h"

int test_bubble_sort(void) {
    return run_sort_test_cases("bubble_sort", bubble_sort, 1);
}
