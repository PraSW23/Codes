#include<iostream>
using namespace std;

class shape{
    virtual double area()=0;
    virtual double perimeter()=0;
};

class rectangle : shape{
    double height, width;
    public:
    rectangle(double h, double w) : height(h), width(w){};

    double area(){
        return height*width;
    }
    
    double perimeter(){
        return 2*(width+height);
    }

    void getHeight(){
        cout<<"height is "<<height<<endl;
    }
};

class circle : shape{
    double radius;

    public :

    circle(double r) : radius(r){};

    double area(){
        return 3.14*radius*radius;
    }

    double perimeter (){
        return 3.14*2*radius;
    }

};

int main(){

    rectangle r1(15,15);
    r1.getHeight();
    cout<<r1.perimeter()<<endl;
    circle c1(7);
    cout<<"area of circle is "<<c1.area()<<" and perimeter is : "<<c1.perimeter()<<endl;
    return 0;
}