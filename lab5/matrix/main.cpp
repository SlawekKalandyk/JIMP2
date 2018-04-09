//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

using ::std::cout;
using ::std::endl;
using namespace algebra;

int main(int argc, char* argv[]){
    //Matrix m1("[3i0, 2i0; 4i0, 5i0]");
    //Matrix m2("[2i0, 4i0; 5i0, 7i0]");
    Matrix m1{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
    Matrix m2{{7. + 1.0i, 12. + 1.3i, 1.5 + 3.7i, 1.0i}, {15. + 2.0i, 2. + 4.6i, 2.1 + 3.8i, 1.4 + 0.2i}};

/*
    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;*/
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    //cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    //cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    //cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
}