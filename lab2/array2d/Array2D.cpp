//
// Created by kalaslaw on 06.03.18.
//

#include "Array2D.h"

int **NewArray2D(int n_rows, int n_columns){
    if(CheckIfInputEqualsOrLowerThanZero(n_rows, n_columns)){
        return 0;
    }

    int **array = new int *[n_rows];

    for(int i = 0; i < n_rows; i++){
        array[i] = new int [n_columns];
    }

    FillArray2D(n_rows, n_columns, array);
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i = 0; i < n_rows; i++){
        delete[] array[i];
    }

    delete[] array;
}

void FillArray2D(int k_rows, int k_columns, int **to_fill) {
    for(int i = 0; i < k_rows; i++) {
        for(int j = 0; j < k_columns; j++) {
            to_fill[i][j] = j + 1 + i * k_columns;
        }
    }
}

int CheckIfInputEqualsOrLowerThanZero(int n_rows, int n_columns) {
    if(n_rows <= 0 || n_columns <= 0){
        return 1;
    }

    return 0;
}