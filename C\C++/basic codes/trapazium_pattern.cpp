#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter the value of N : ";
    cin>>num;
    int temp=1, last=0;

    for (int i = 0; i < num; i++)
    {
        /* code */
        last=last+(num-i);
    }
    last*=2;
    

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <(num-i) ; j++)
        {
            /* code */
            cout<<temp++<<" ";

        }
        
        last = last - (num-i);
        int st = last + 1;
        for (int j = 0; j <(num-i) ; j++)
        {
            /* code */
            cout<<st++<<" ";
            
        }
        cout<<endl;
    }
    


    return 0;
}
