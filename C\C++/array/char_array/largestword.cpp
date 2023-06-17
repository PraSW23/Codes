#include<iostream>
using namespace std;

int main(){
int count=0,word=0,max=0,maxw=0,i=0; 
char arr[1000]="hello my name is tiger";
//cout<<"Enter sentence : ";
//cin>>arr;

while (arr[i]!='\0')
{   
    if (arr[i] != ' ')
    {
        count++;
        //cout<<"count = "<<count<<endl;
    }
    else {
            word++;
            if (max<count)
            {
                max = count;
                maxw = word;  
            }
            count = 0;
    }
    i++;
}
 
 if (count>max)
 {
     max = count;
     maxw = ++word;

 }
 

 cout<<"\nLongest word is word "<<maxw<<" of length "<<max<<endl;
 return 0;

}