#include <stdio.h>

#include "test_sorting.h"
#include "test_utils.h"

int main(void) {
    int failures = 0;

    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_bucket_sort);
    RUN_TEST(test_counting_sort);
    RUN_TEST(test_heap_sort);
    RUN_TEST(test_insertion_sort);
    RUN_TEST(test_merge_sort);
    RUN_TEST(test_quick_sort);
    RUN_TEST(test_selection_sort);
    RUN_TEST(test_shell_sort);
    RUN_TEST(test_radix_sort);

    if (failures == 0) {
        printf("\nAll tests passed.\n");
        return 0;
    }

    printf("\nTotal failed cases: %d\n", failures);
    return 1;
}
