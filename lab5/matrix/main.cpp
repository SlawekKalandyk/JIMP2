//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

using ::std::cout;
using ::std::endl;
using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m1(argv[1]);
    Matrix m2(argv[2]);

    cout << "Macierz pierwsza: " << m1.print() << endl;
    cout << "Macierz druga: " << m2.print() << endl;

    cout << "Dodawanie" << (m1.add(m2)).print() << endl;
    cout << "Odejmowanie" << (m1.sub(m2)).print() << endl;
    cout << "Mnożenie" << (m1.mul(m2)).print() << endl;
    cout << "Dzielenie" << (m1.div(m2)).print() << endl;
    cout << "Potęgowanie" << (m1.pow(2)).print() << endl;
    cout << "Potęgowanie" << (m2.pow(2)).print() << endl;
}