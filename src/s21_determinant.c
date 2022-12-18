#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  matrix_t tmp = {0};
  *result = 0;
  if (A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      res = s21_create_matrix(A->rows, A->rows, &tmp);
      if (res == OK) {
        *result = det(A, A->rows);
        s21_remove_matrix(&tmp);
      }
    } else {
      res = CALC_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

double det(matrix_t *tmp, int n) {
  double determinant = 0;
  if (n == 1) {
    determinant = tmp->matrix[0][0];
  } else if (n == 2) {
    determinant = tmp->matrix[0][0] * tmp->matrix[1][1] -
                  tmp->matrix[0][1] * tmp->matrix[1][0];
  } else {
    matrix_t tmp2 = {0};
    int res = s21_create_matrix(n, n, &tmp2);
    if (res == OK) {
      int sign = 1;
      for (int i = 0; i < n; i++) {
        get_cofactor(tmp, &tmp2, 0, i, n);
        determinant += sign * tmp->matrix[0][i] * det(&tmp2, n - 1);
        sign = -sign;
      }
      s21_remove_matrix(&tmp2);
    }
  }
  return determinant;
}

void get_cofactor(matrix_t *A, matrix_t *dest, int row, int col, int n) {
  dest->rows = n - 1;
  dest->columns = n - 1;
  int offset_row = 0;
  int offset_columns = 0;
  for (int i = 0; i < n; i++) {
    if (i == row) offset_row = 1;
    offset_columns = 0;
    for (int j = 0; j < n; j++) {
      if (j == col) offset_columns = 1;
      if (i != row && j != col)
        dest->matrix[i - offset_row][j - offset_columns] = A->matrix[i][j];
    }
  }
}