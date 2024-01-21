#include<iostream>
using namespace std;

int main(){

    int arr[] = {4,2,6,9,7,3,8,1};

    for (int i = 0; i < 8; i++)
    {   
        int temp = i;
        while ((arr[temp-1] > arr[temp]) && temp!=0)
        {
            int tmp = arr[temp];
            arr[temp] = arr[temp-1];
            arr[temp-1] = tmp;
            temp--;
        }
        
    }
    
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;

    return 0;
}