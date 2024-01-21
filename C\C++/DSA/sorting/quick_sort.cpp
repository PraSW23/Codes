#include <bits/stdc++.h>
using namespace std;

void pt(int * arr){

    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;

}

int partition(int i, int j, int * arr){
    int temp = i++;

    while (j >= i)
    {

        if (arr[temp] >= arr[i])
        {
            i++;
        }

        if (arr[temp] < arr[j])
        {
            j--;
        }
        
        if (arr[temp] < arr[i] && arr[temp] >= arr[j] && j>i)
        {
            swap(arr[i],arr[j]);
        }
        
    }
    
    swap(arr[temp],arr[j]);
    return j;
}

void quick(int low, int high, int * arr){


if (low < high)
{   
     int temp = partition(low, high, arr);
     quick(low, temp-1, arr);
     quick(temp+1, high, arr);

}
    

}

int main(){

     int arr[] = {4,2,6,9,7,3,8,1,99,0};
     int size = sizeof(arr)/sizeof(arr[0]);

    quick(0, size-1, arr);

    pt(arr);

    return 0;
}