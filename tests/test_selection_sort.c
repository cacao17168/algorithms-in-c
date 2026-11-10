#include "sorting.h"
#include "test_utils.h"

int test_selection_sort(void) {
    return run_sort_test_cases("selection_sort", selection_sort, 1);
}
