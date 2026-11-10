#include "sorting.h"
#include "test_utils.h"

int test_shell_sort(void) {
    return run_sort_test_cases("shell_sort", shell_sort, 1);
}
