#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns && A->rows != 1) {
      s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double determinant = 0;
          int x = s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
          s21_get_matrix(i, j, A, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant;
          if (x == 0) s21_remove_matrix(&minor);
        }
      }
    } else {
      res = CALC_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}