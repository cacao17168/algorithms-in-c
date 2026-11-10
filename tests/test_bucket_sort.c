#include "sorting.h"
#include "test_utils.h"

int test_bucket_sort(void) {
    int failures = 0;

    int a0[] = {0};
    bucket_sort(a0, 0);

    int a1[] = {0};
    bucket_sort(a1, 1);
    if (a1[0] != 0) {
        printf("  FAIL bucket_sort [single zero]\n");
        failures++;
    }

    int a5[] = {0, 0, 0, 0, 0};
    bucket_sort(a5, 5);
    for (size_t i = 0; i < 5; i++) {
        if (a5[i] != 0) {
            printf("  FAIL bucket_sort [zeros]\n");
            failures++;
            break;
        }
    }
    return failures;
}
