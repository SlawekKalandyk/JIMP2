//
// Created by kalaslaw on 06.03.18.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

int **NewArray2D(int n_rows, int n_columns);
void DeleteArray2D(int **array, int n_rows, int n_columns);
void FillArray2D(int k_rows, int k_columns, int **to_fill);
int CheckIfInputEqualsOrLowerThanZero(int n_rows, int n_columns);

#endif //JIMP_EXERCISES_ARRAY2D_H
