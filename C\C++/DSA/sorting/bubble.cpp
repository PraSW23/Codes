#include<iostream>
using namespace std;

int main(){

    int arr[] = {4,2,6,9,7,3,8,1};
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 8; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }
    
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}