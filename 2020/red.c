#include <stdio.h>

int main(void) {
  // Read in the values of N and R from standard input
  int N, R;
  scanf("%d %d", &N, &R);

  // Read in the values of the array A from standard input
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize a counter to keep track of the number of index pairs that satisfy the conditions
  int counter = 0;

  // Iterate through the array A and check for index pairs (i, j) that satisfy the conditions
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[j] - A[i] > R) {
        counter++;
      }
    }
  }

  // Print the result to standard output
  printf("%d\n", counter);

  return 0;
}