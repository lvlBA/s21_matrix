#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = INCORRECT_MATRIX;
  if (rows > 0 && columns > 0) {
    double **matrix =
        calloc(rows * columns * sizeof(double) + rows * sizeof(double *), 1);

    if (matrix != NULL) {
      double *ptr = (double *)(matrix + rows);
      for (int i = 0; i < rows; i += 1) {
        matrix[i] = ptr + columns * i;
      }
      result->columns = columns;
      result->matrix = matrix;
      result->rows = rows;
      res = OK;
    }
  }
  return res;
}
