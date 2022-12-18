#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (s21_is_empty(A) == 0 && s21_is_empty(B) == 0 &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && ret; i++) {
      for (int j = 0; j < A->columns && ret; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          ret = FAILURE;
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}
