#include<iostream>
using namespace std;
int n1;

bool check(int arr[4][4], int n, int i){
for (int j = 0; j < n; j++)
{
    if (arr[i][j]==2)
    {
        return true;
    }
    
}
return false;

}


void nqeen(int n, int arr[4][4], int i, int j){
cout<<"hello\n";
if((i==n)||(j==n)){
    return;
}

if((arr[i][j]!=1)&&(arr[i][j]!=2)){
    arr[i][j]=2;
}

if(arr[i][j]==2){

for (int p = j; p < n; p++)
{
    arr[i][p] = 1;
    
}   
for (int p = i; p < n; p++)
{
    arr[p][j] = 1;
    
}

for (int p = i; p < n; p++)
{
    for (int q = j; q < n; q++)
    {
        arr[p][q] = 1;
    }
    
}

for (int p = i; p < n; p--)
{
    for (int q = j; q > -1; q--)
    {
        arr[p][q] = 1;
    }
    
}

}


int l;
if(j==n-1)
if(!check(arr,n,i)){
   // int l;
    arr[i][j] = 0;

for (l = 0; l < n; l++)
{
    if(arr[i-1][l]==2)
    break;
}

arr[i-1][l] = 0;

for (int p = j; p < n; p++)
{
    arr[i][p] = 0;
    arr[i-1][p] = 0;
}   
for (int p = i; p < n; p++)
{
    arr[p][j] = 0;
    arr[p-1][j] = 0;
    
}

for (int p = i; p < n; p++)
{
    for (int q = j; q < n; q++)
    {
        arr[p][q] = 0;
        arr[p-1][q] = 0;
    }
    
}

for (int p = i; p < n; p--)
{
    for (int q = j; q > -1; q--)
    {
        arr[p][q] = 0;
        arr[p-1][q] = 0;

    }
    
}
    
}



 if(j<n){
 nqeen(n,arr,i,j+1);
 }
 else if(i<n){
    j=0;
    nqeen(n,arr,i+1,j);
 }

}



int main(){
int n=4;
//cout<<"Enter the number of queens or size of board : ";
//cin>>n;
int arr[4][4];
n1 = n;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        arr[i][j] = 0;
    }
    
}


nqeen(n,arr,0,0);

cout<<"ans is";
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
}


return 0;
}