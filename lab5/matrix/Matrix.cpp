//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

namespace algebra {

    Matrix::Matrix(const string str) {
        int subBegin, subEnd, elementCounter = 0;
        double real, imag;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ',') {
                cols++;
            }

            if (str[i] == ';' || str[i] == ']') {
                rows++;
            }
        }

        cols = cols / rows + 1;

        matrix = new std::complex<double>[rows * cols];

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

                while (str[i] != ',' && str[i] != ';' && str[i] != ']') {
                    i++;
                }

                subEnd = i;
                imag = stod(str.substr(subBegin, subEnd - subBegin));

                matrix[elementCounter] = {real, imag};
                elementCounter++;
            }
        }
    }

    Matrix::Matrix(initializer_list<vector<std::complex<double>>> list) {
        rows = list.size();
        cols = (*list.begin()).size();
        matrix = new std::complex<double>[rows * cols];

        initializer_list<vector<std::complex<double>>>::iterator it = list.begin();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i * cols + j] = it[i][j];
            }
        }
    }

    Matrix::~Matrix() {
        delete[] matrix;
    }

    Matrix::Matrix(const Matrix &matrix) {

    }

    Matrix::Matrix(Matrix &&matrix) {

    }

    Matrix &Matrix::operator=(const Matrix &matrix) {

    }

    Matrix &Matrix::operator=(Matrix &&matrix) {

    }

    Matrix Matrix::Add(const Matrix &input) const {
        Matrix result{rows, cols};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i * cols + j] = this->matrix[i * cols + j] + input.matrix[i * cols + j];
            }
        }
    }

    Matrix Matrix::Sub(const Matrix &input) const {
        Matrix result{rows, cols};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i * cols + j] = this->matrix[i * cols + j] - input.matrix[i * cols + j];
            }
        }
    }

    Matrix Matrix::Mul(const Matrix &input) const {
        Matrix result{rows, cols};
        std::complex<double> dataHolder;

        if (cols == input.rows) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < input.cols; j++) {
                    for (int n = 0; n < cols; n++) {
                        dataHolder += this->matrix[i * cols + n] * input.matrix[n * cols + j];
                    }

                    result.matrix[i * cols + j] = dataHolder;
                }
            }
        }

        return result;
    }

    Matrix Matrix::Mul(const std::complex<double> &n) const {
        Matrix result{rows, cols};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i * cols + j] = n * this->matrix[i * cols + j];
            }
        }
    }

    Matrix Matrix::Div(const Matrix &input) const {

    }

    Matrix Matrix::Div(const std::complex<double> &n) const {
        Matrix result{rows, cols};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (n.real() == 0 && n.imag() == 0) {}
                else {
                    result.matrix[i * cols + j] = this->matrix[i * cols + j] / n;
                }
            }
        }
    }

    Matrix Matrix::Pow(const int &power) const {
        Matrix result{rows, cols};
        result.matrix = matrix; // to do

        for (int i = 0; i < power; i++) {
            result = result.Mul(result);
        }

        return result;
    }

    string Matrix::Print() const {
        string result;
        string strReal, strImag;
        result += '[';

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                strReal = to_string(matrix[i * cols + j].real());
                while (strReal[strReal.size() - 1] == '0') {
                    strReal = strReal.substr(0, strReal.size() - 1);
                }
                if (strReal[strReal.size() - 1] == '.') {
                    strReal = strReal.substr(0, strReal.size() - 1);
                }

                strImag = to_string(matrix[i * cols + j].imag());
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
        return {rows, cols};
    }

}