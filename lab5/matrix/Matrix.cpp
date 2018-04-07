//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

namespace algebra {

    Matrix::Matrix(string str) {
        int subBegin, subEnd, elementCounter = 0;
        double real, imaginary;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
                subBegin = i;

                while (str[i] != 'i') {
                    i++;
                }

                subEnd = i;
                real = stod(str.substr(subBegin, subEnd - subBegin));
            }

            if (str[i] == 'i') {
                i++;
                subBegin = i;

                while (str[i] != ',' && str[i] != ';') {
                    i++;
                }

                subEnd = i;
                imaginary = stod(str.substr(subBegin, subEnd - subBegin));
            }

            matrix[elementCounter] = {real, imaginary};
            elementCounter++;
            cols++;
        }

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ';' || str[i] == ']') {
                rows++;
            }
        }

        cols /= rows;
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

    Matrix Matrix::Add(const Matrix &input) {

    }

    Matrix Matrix::Sub(const Matrix &input) {

    }

    Matrix Matrix::Mul(const Matrix &input) {

    }

    Matrix Matrix::Div(const Matrix &input) {

    }

    Matrix Matrix::Pow(const int &power) {

    }

    string Matrix::Print() {
        string result;
        string strReal, strImag;
        result += '[';

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                strReal = to_string(this->matrix[i * this->cols + j].real());
                while (strReal[strReal.size() - 1] == '0') {
                    strReal = strReal.substr(0, strReal.size() - 1);
                }
                if (strReal[strReal.size() - 1] == '.') {
                    strReal = strReal.substr(0, strReal.size() - 1);
                }

                strImag = to_string(this->matrix[i * this->cols + j].imag());
                while (strImag[strImag.size() - 1] == '0') {
                    strImag = strImag.substr(0, strImag.size() - 1);
                }
                if (strImag[strImag.size() - 1] == '.') {
                    strImag = strImag.substr(0, strImag.size() - 1);
                }

                result += strReal + 'i' + strImag;
                result += ", ";
            }

            result = result.substr(0, result.size() - 2);
            result += "; ";
        }

        result = result.substr(0, result.size() - 2);
        result += ']';

        return result;
    }

    vector<int> Matrix::Size() {
        return {this->rows, this->cols};
    }

}