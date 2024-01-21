#include<iostream>
using namespace std;

class Emp {
public:
    void work() {
        cout << "ok" << endl;
    }

protected:
    Emp() {
        cout << "HI coder " << endl;
    }
    
    int add(int n1, int n2, int n3) {
        return n1 + n2 + n3;
    }

    // Declare the adding function as a friend function
    friend int adding(int n1, int n2, int n3);
public:
    // Public method to access the private add method
    int accessAdd(int n1, int n2, int n3) {
        return add(n1, n2, n3);
    }
};

int adding(int n1, int n2, int n3) {
    Emp emp;
    return emp.add(n1, n2, n3);
}

class Coder : public Emp {
public:
    void work() {
        cout << "Nice" << endl;
    }
};

int main() {
    Coder c1; 
    int result = c1.accessAdd(1, 2, 3);
    cout << "Result: " << result << endl; // Output will be "Result: 6"
    cout<<adding(1,5,2)<<endl;
    return 0;
}
