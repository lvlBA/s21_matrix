#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_is_empty(A) || s21_is_empty(A)) {
    res = 1;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    res = CALC_ERROR;
  } else if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return res;
}