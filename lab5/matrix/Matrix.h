//
// Created by slawek on 01.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <string>
#include <vector>

using ::std::string;
using ::std::initializer_list;
using ::std::vector;
namespace algebra {
    class Matrix {
    public:
        Matrix() {};

        Matrix(const int &nrows, const int &ncols) : rows(nrows), cols(ncols) {};

        Matrix(initializer_list<vector<std::complex<double>>> list);

        Matrix(string str);

        ~Matrix();

        Matrix Add(const Matrix &matrix);

        Matrix Sub(const Matrix &matrix);

        Matrix Mul(const Matrix &matrix);

        Matrix Div(const Matrix &matrix);

        Matrix Pow(const Matrix &matrix);

        string Print(const Matrix &matrix);

        vector<int> Size();


    private:
        int rows = 0, cols = 0;
        std::complex<double> *matrix = nullptr;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
