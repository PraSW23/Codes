#include<iostream>
using namespace std;

int main(){
int n,count=0,word=0,max=0,maxw=0,i=0,startp; 
cout<<"Enter size: ";
cin>>n;
cin.ignore();
char arr[n+1];
cout<<"Enter sentence : ";
cin.getline(arr,n);
cin.ignore();

//char arr[100] = "hello how are youhjl";

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
                startp = i-max;
            }
            count = 0;
    }
    i++;
}

 if (count>max)
 {
     max = count;
     maxw = ++word;
     startp = i-max;
 }
 

 cout<<"\nLongest word is word "<<maxw<<" of length "<<max<<" and word is ";
    //cout<<"startp = "<<startp<<endl;
i = startp;
 while (i < max + startp)
 {
    cout<<arr[i++];

 }
 cout<<endl;

 return 0;

}