#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef void (*sort_fn_t)(int[], size_t);

static inline void print_array(const int *a, size_t n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d%s", a[i], i + 1 < n ? ", " : "");
    }
    printf("]");
}

static inline int arrays_equal(const int *a, const int *b, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

static inline int run_sort_test_cases(const char *fn_name, sort_fn_t fn, int with_negative) {
    struct TestCase {
        const char *name;
        int input[10];
        size_t n;
        int expected[10];
    };

    struct TestCase cases[] = {
        {"empty",              {0},                 0, {0}},
        {"single",             {42},                1, {42}},
        {"already sorted",     {1, 2, 3, 4, 5},     5, {1, 2, 3, 4, 5}},
        {"reverse",            {5, 4, 3, 2, 1},     5, {1, 2, 3, 4, 5}},
        {"duplicates",         {3, 1, 2, 3, 1, 2},  6, {1, 1, 2, 2, 3, 3}},
        {"mixed non-negative", {7, 0, 4, 0, 2, 7, 1}, 7, {0, 0, 1, 2, 4, 7, 7}},
        {"negative",           {-3, 0, -1, 2, -2, 1}, 6, {-3, -2, -1, 0, 1, 2}},
        {"mixed",              {9, -1, 4, 0, 4, -5, 2}, 7, {-5, -1, 0, 2, 4, 4, 9}}
    };

    size_t count = with_negative ? (sizeof(cases) / sizeof(cases[0])) : 6;
    int failures = 0;

    for (size_t c = 0; c < count; c++) {
        int arr[10];
        memcpy(arr, cases[c].input, cases[c].n * sizeof(int));

        fn(arr, cases[c].n);

        if (!arrays_equal(arr, cases[c].expected, cases[c].n)) {
            printf("  FAIL %s [%s]\n", fn_name, cases[c].name);
            printf("    expected: "); print_array(cases[c].expected, cases[c].n); printf("\n");
            printf("    actual:   "); print_array(arr, cases[c].n); printf("\n");
            failures++;
        }
    }

    return failures;
}

#define RUN_TEST(fn) do { \
    int f = fn(); \
    if (f == 0) { \
        printf("[ OK ] %s\n", #fn); \
    } else { \
        printf("[FAIL] %s (%d failed case(s))\n", #fn, f); \
        failures += f; \
    } \
} while (0)

#endif
