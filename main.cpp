#include <stdio.h>
#define SIZE 5
// Name: Daniel Van Dalsem
// KU ID: 3129614

// Instucted I don't need to return anything.
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]) {
  // due to the use of the size variable, it will always by SIZExSIZE, thus we
  // can add the two up.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      m3[i][j] = m1[i][j] + m2[i][j];
    }
  }
}
void transposeMatrix(int m1[SIZE][SIZE], int m3[SIZE][SIZE]) {
  // just flip the i and j variables to traspose.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      m3[j][i] = m1[i][j];
    }
  }
}
void multiplyMatrix(int m1[SIZE][SIZE], int m2[SIZE][SIZE],
                    int m3[SIZE][SIZE]) {
  // This is really hard for me to visualize, especially because I have not
  // taken linear alagbra. partatually because of that, I am not quite sure this
  // is correct.
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        m3[i][j] += m1[k][j] * m2[i][k];
      }
    }
  }
}
void printMatrix(int m3[SIZE][SIZE]) {
  // print for convionce and testing.
  for (int s = 0; s < SIZE; s++) {
    for (int i = 0; i < SIZE; i++) {
      printf("%d ", m3[s][i]);
    }
    printf("\n");
  }
}
int main(int argc, char *argv[]) {
  int m1[SIZE][SIZE] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};
  int m2[SIZE][SIZE] = {{25, 24, 23, 22, 21},
                        {20, 19, 18, 17, 16},
                        {15, 14, 13, 12, 11},
                        {
                            10,
                            9,
                            8,
                            7,
                            6,
                        },
                        {5, 4, 3, 2, 1}};
  int m3[SIZE][SIZE];
  printf("Original matrix 1:\n");
  printMatrix(m1);
  printf("\n");
  printf("Original matrix 2:\n");
  printMatrix(m2);
  printf("\nm1+m2:\n");
  addMatrices(m1, m2, m3);
  printMatrix(m3);
  printf("\n");
  printf("m1 transposed:\n");
  transposeMatrix(m1, m3);
  printMatrix(m3);
  printf("\n");
  printf("m1*m1:\n");
  multiplyMatrix(m1, m2, m3);
  printMatrix(m3);

  return 1;
}
