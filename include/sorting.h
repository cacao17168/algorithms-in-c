#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

void bubble_sort(int arr[], size_t n);

void bucket_sort(int arr[], size_t n);

void counting_sort(int arr[], size_t n);

void heap_sort(int arr[], size_t n);

void insertion_sort(int arr[], size_t n);

void merge_sort(int arr[], size_t left, size_t right);

void quick_sort(int arr[], size_t low, size_t high);

void selection_sort(int arr[], size_t n);

void shell_sort(int arr[], size_t n);

#endif
