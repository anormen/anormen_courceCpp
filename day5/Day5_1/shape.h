#ifndef SHAPES_H
#define SHAPES_H
#include<iostream>
#include<cmath>


class Shape {
public:
    Shape() = default;
    Shape(const int &_p, const int &_a):Perimiter(_p),Area(_a){}
    virtual ~Shape() = 0;
    bool operator <(const Shape &s);
    bool operator >(const Shape &s);
    bool operator ==(const Shape &s);
    void print() {
        std::cout << Perimiter << " " << Area << std::endl;
    }
private:
    int Perimiter = 0, Area = 0;
};

class Circle : public Shape {
public:
    ~Circle() = default;
    Circle(const int &radius):Shape((2*radius*3),std::pow(radius,2)){}
};

class Rectangle : public Shape {
  public:
    ~Rectangle() = default;
    Rectangle(const int &height,const int &width):Shape((2*height)+(2*width),(height*width)){}
};

class Triangle : public Shape {
  public:
    ~Triangle() = default;
    Triangle(const int &width,const int &height):Shape(3*width,height*width/2){}
};

template <typename C1, typename C2>
bool isEqual(C1 const& A, C2 const& B){
    bool isEq;
    isEq = (A == B);
    std::cout << "isEqual " << (isEq ? "true" : "false" ) << std::endl;
;   return isEq;
}



#endif // SHAPES_H