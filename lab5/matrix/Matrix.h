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
using ::std::stoi;
using ::std::to_string;
using ::std::cout;
using ::std::endl;

namespace algebra {
    class Matrix {
    public:
        Matrix() {};

        Matrix(const int &nrows, const int &ncols) : rows(nrows), cols(ncols) {
            matrix = new std::complex<double>[rows * cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i * cols * j] = 0;
                }
            }
        };

        Matrix(initializer_list<vector<std::complex<double>>> list);

        Matrix(const string str);

        ~Matrix();

        Matrix(const Matrix &matrix); // copy constructor

        Matrix(Matrix &&matrix); // move constructor

        Matrix &operator=(const Matrix &matrix); // copy operator

        Matrix &operator=(Matrix &&matrix); // move operator

        Matrix Add(const Matrix &input) const;

        Matrix Sub(const Matrix &input) const;

        Matrix Mul(const Matrix &input) const;

        Matrix Mul(const std::complex<double> &n) const;

        Matrix Div(const Matrix &input) const;

        Matrix Div(const std::complex<double> &n) const;

        Matrix Pow(const int &power) const;

        string Print() const;

        vector<int> Size();


    private:
        int rows = 0, cols = 0;
        std::complex<double> *matrix = nullptr;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
