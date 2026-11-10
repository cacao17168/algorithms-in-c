#include "sorting.h"
#include "test_utils.h"

int test_insertion_sort(void) {
    return run_sort_test_cases("insertion_sort", insertion_sort, 1);
}
