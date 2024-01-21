#include<iostream>

using namespace std;


class Rectangle{
    
    float length;
    float breadth;

    public:
    
    void Setperi(float l, float b){
        this->length = l;
        breadth = b;
    }

    pair <int , int> Getperi(){
        pair <int , int >p;
        p.first = length;
        p.second = breadth;
        return p;
    }
    Rectangle(float l, float b);
    Rectangle(Rectangle *rect){
        this->length = rect->length;
        breadth = rect->breadth;
    }
    /*
    if Rectangle r2(r1); is written
    Rectangle(Rectangle &rect){
        length = rect.length;
        breadth = rect.breadth;
    }*/
    
    private:
    friend float calculateArea(const Rectangle& rect);
    float area() const;
};

float Rectangle::area() const{
    return length*breadth;
}

Rectangle::Rectangle(float l=0, float b=0){
        this->length = l;
        breadth = b;
    }

float calculateArea(const Rectangle& rect) { // const obj bhej raha hu toh woh fun modify na karde isliye fun ko
// gaurntee deni hogi ki modify nahi karega is const lagaya hua hai area fun ke baad jo gaurntee de raha hai
    return rect.area();
}


int main(){
    Rectangle r1(2,3);
    //cout<<"area = "<<r1.area();
    
    Rectangle r2(&r1);
    pair<int, int> p = r2.Getperi();
    cout << "Length = " << p.first << ", Breadth = " << p.second << endl;
    float ar = calculateArea(r1);
    

}