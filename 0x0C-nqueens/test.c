/*
 * Author: Hiroyuki Chishiro
 * License: 2-Clause BSD
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define N 4
 
void print_queen(int row[], int *solutions)
{
  int i, j;
 
  printf("\n[Solution %d]\n", *solutions);
 
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
        printf("%d", row[i]);
    printf("\n");
  }
}
 
bool check(int queen_position, int row[])
{
  int i, j;
 
  for (i = 1; i <= queen_position; i++) {
    for (j = 0; j < i; j++) {
      if (row[i] == row[j] || abs(row[i] - row[j]) == i - j) {
        return false;
      }
    }
  }
 
  return true;
}
 
void brute_force(int n, int queen_position, int row[], int *solutions)
{
  for (row[n] = 0; row[n] <= queen_position; row[n]++) {
    if (n == queen_position) {
      if (check(queen_position, row)) {
        (*solutions)++;
        print_queen(row, solutions);
      }
    } else {
      brute_force(n + 1, queen_position, row, solutions);
    }
  }
}
 
int main(void)
{
  int row[N];
  int solutions = 0;
 
  brute_force(0, N - 1, row, &solutions);
 
  printf("solutions = %d\n", solutions);
 
  return 0;
}

