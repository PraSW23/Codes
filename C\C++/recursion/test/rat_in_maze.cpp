#include<iostream>
using namespace std;


bool maz(int arr[][5], int x, int y, int n, int solArr[][5]){

for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           
            solArr[i][j] = 1;
        }   
    }
    return true;
}

int main(){

     int n = 5;
    // cout<<"Enter value of n : "<<endl;
    // cin
    int arr[5][5], solArr[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>arr[i][j];
            solArr[i][j] = 0;
        }   
    }

    bool is = maz(arr, 0, 0, n, solArr);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<solArr[i][j]<<" ";
        }   
        cout<<endl;
    }

    return 0;
}

/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/