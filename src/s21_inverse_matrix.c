#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (s21_is_empty(A)) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res = CALC_ERROR;
  } else {
    double d = 0.0;
    res = s21_create_matrix(A->rows, A->columns, result);
    if (res == OK && A->rows) {
      s21_determinant(A, &d);
      if (fabs(d) < 1e-6) {
        res = CALC_ERROR;
      } else if (A->rows == 1) {
        if (res == OK) {
          result->matrix[0][0] = 1.0 / A->matrix[0][0];
        }
      } else {
        matrix_t tmp1 = {0};
        s21_calc_complements(A, &tmp1);
        matrix_t tmp = {0};
        s21_transpose(&tmp1, &tmp);
        int size = A->rows;
        for (int i = 0; i < size; i++)
          for (int j = 0; j < size; j++)
            result->matrix[i][j] = tmp.matrix[i][j] / d;
        s21_remove_matrix(&tmp1);
        s21_remove_matrix(&tmp);
      }
    }
  }
  return res;
}
