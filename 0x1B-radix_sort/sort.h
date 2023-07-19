#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
int get_max(int *array, size_t size);
void count_sort(int arr[], int n, int exp);
void radix_sort(int *array, size_t size);

#endif
