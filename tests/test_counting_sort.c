#include "sorting.h"
#include "test_utils.h"

int test_counting_sort(void) {
    return run_sort_test_cases("counting_sort", counting_sort, 0);
}
