#include "sorting.h"
#include "test_utils.h"

int test_radix_sort(void) {
    return run_sort_test_cases("radix_sort", radix_sort, 0);
}
