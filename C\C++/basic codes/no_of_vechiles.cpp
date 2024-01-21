#include<iostream>
using namespace std;

int main(){
    
    int vechiles,wheels;
    cout<<"Enter Values of Vechile and Wheels : ";
    cin>>vechiles>>wheels;

    int two_wheeler = wheels - vechiles*2;
    int tmp = two_wheeler;
    

    while (tmp%4!=0)
        tmp--;
    
    int four_wheeler = tmp/2;
    two_wheeler = vechiles - four_wheeler;

    cout<<"Two Wheeler : "<<two_wheeler<<"\nFour Wheeler : "<<four_wheeler<<endl;

    return 0;
}