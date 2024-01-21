#include<iostream>
using namespace std;

int main(){

    int arr[] = {4,2,6,9,7,3,8,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {   
        int min = arr[i];
        for (int j = i+1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                arr[j] = arr[j] + 2*arr[i];
                arr[i] = arr[j] - 2*arr[i];
                arr[j] = (arr[j] - arr[i])/2;

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