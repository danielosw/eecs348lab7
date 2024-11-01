#include <iostream>
using namespace std;
const int SIZE = 4; // Global variable for matrix size
class Matrix {
private:
  int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
public:
  // 1. Read values from stdin into a matrix
  void readFromStdin();
  // 2. Display a matrix
  void display() const;
  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix &other) const {
    Matrix toReturn;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        toReturn.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return toReturn;
  };

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix &other) const {
    Matrix toReturn;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        int list[SIZE];
        int p = 0;
        for (int k = 0; k <= SIZE; k++) {
          list[k] = (data[i][k] * other.data[k][j]);
        }
        int temp = 0;
        for (int k = 0; k <= SIZE; k++) {
          temp = temp + k;
        }
        toReturn.data[i][j] = temp;
      }
    }
    return toReturn;
  };

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;
  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    
    for (int i = 0; i < SIZE; i++) {
        int hold = data[row1][i];
        data[row1][i]=data[row2][i];
        data[row2][i] = hold;
    }
  };
};
int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();
  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();
  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();
  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();
  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();
  return 0;
}