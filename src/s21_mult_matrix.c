#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_is_empty(A) || s21_is_empty(B)) {
    res = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    res = CALC_ERROR;
  } else {
    res = s21_create_matrix(A->rows, B->columns, result);

    if (!res) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int m = 0; m < B->rows; m++)
            result->matrix[i][j] += A->matrix[i][m] * B->matrix[m][j];
        }
      }
    }
  }

  return res;
}