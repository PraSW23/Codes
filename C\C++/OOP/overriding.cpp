#include<iostream>
using namespace std;

class Emp {
public:
    void work() {
        cout << "ok"<<endl;
    }
    int add(int n1, int n2, int n3){
        return n1+n2+n3;
    }
};

class Coder : public Emp {
public:
    void work() {
        cout << "bye"<<endl;
    }
    int add(int n1, int n2){
        return n1+n2;
    }
};

class developer:public Coder{
public:
    void work(){
        cout<<"Nice"<<endl;
    }

};

int main() {
    developer c1;
    c1.Coder::work(); 
    c1.Emp::work();

    cout<<c1.Emp::add(2,3,4)<<endl; 

    return 0;
}
