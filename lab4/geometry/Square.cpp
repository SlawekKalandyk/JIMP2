//
// Created by kalaslaw on 20.03.18.
//

#include "Square.h"
#include <cmath>
#include <ostream>
#include <iostream>

using ::std::ostream;
using ::std::cout;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry{

    Point::Point():x_(0),y_(0){

    }

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point::~Point(){

    }

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return this->x_;
    }

    double Point::GetY() const {
        return this->y_;
    }

    void Point::SetX(double x) {
        this->x_ = x;
    }

    void Point::SetY(double y) {
        this->y_ = y;
    }

    Square::Square(Point p1, Point p2, Point p3, Point p4) {
        
        this->p1_ = p1;
        this->p2_ = p2;
        this->p3_ = p3;
        this->p4_ = p4;
    }

    double Square::Circumference() {
        double circumference;

        circumference = 4 * p1_.Distance(p2_);

        return circumference;
    }

    double Square::Area() {
        double area;

        area = (pow(p1_.Distance(p2_), 2));

        return area;
    }

}
