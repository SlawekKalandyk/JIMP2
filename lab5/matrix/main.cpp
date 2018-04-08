//
// Created by slawek on 01.04.18.
//

#include "Matrix.h"

using ::std::cout;
using ::std::endl;
using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m1("[3i0, 2i3; 4i8, 5i0]");
    //Matrix m2(argv[2]);


    cout << "Macierz pierwsza: " << m1.Print() << endl;
    //cout << "Macierz druga: " << m2.Print() << endl;
/*
    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl; */
}