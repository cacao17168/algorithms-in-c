#include "sorting.h"
#include "test_utils.h"

int test_heap_sort(void) {
    return run_sort_test_cases("heap_sort", heap_sort, 1);
}
