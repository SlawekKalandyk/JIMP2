//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

namespace algebra {

    Matrix::Matrix(string str) {
        int subBegin, subEnd, colCounter, rowCounter;
        for(int i = 0; i < str.size(); i++) {

        }
    }

    Matrix::Matrix(initializer_list<vector<std::complex<double>>> list) {
        this->rows = list.size();
        this->cols = (*list.begin()).size();
        this->matrix = new std::complex<double>[this->rows * this->cols];

        initializer_list<vector<std::complex<double>>>::iterator it = list.begin();

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                this->matrix[j + i * this->cols] = it[i][j];
            }
        }
    }

    Matrix::~Matrix() {
        delete[] this->matrix;
    }

    Matrix Matrix::Add(const Matrix &matrix) {

    }

    Matrix Matrix::Sub(const Matrix &matrix) {

    }

    Matrix Matrix::Mul(const Matrix &matrix) {

    }

    Matrix Matrix::Div(const Matrix &matrix) {

    }

    Matrix Matrix::Pow(const Matrix &matrix) {

    }

    string Matrix::Print(const Matrix &matrix) {

    }

    vector<int> Matrix::Size() {
        return {this->rows, this->cols};
    }

}