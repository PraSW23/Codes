//apna college
#include<iostream>
using namespace std;

struct sack
{
    int weight;
    int profit;
};
//int maxi=0;


int knap(int cap, sack s[], int n){
if (n==0||cap==0)
{
    return 0;
}

if(s[n-1].weight>cap){
       return knap(cap,s,n-1);
}

return max((knap(cap-s[n-1].weight,s,n-1)+s[n-1].profit),(knap(cap,s,n-1)));

}



int main(){
 int knapsack_cap=40,maxi;
 sack s[4];
 s[0].weight = 25;
 s[0].profit = 40;
 s[1].weight = 15;
 s[1].profit = 30;
 s[2].weight = 10;
 s[2].profit = 15;
 s[3].weight = 30;
 s[3].profit = 45;

 maxi = knap(knapsack_cap,s,4);
cout<<"Maximum profit : "<<maxi<<endl;
//cout<<"object included are of weight : "<<endl;
//for (int i = 0; i < 4; i++)
//{   if(obj[i]!=0)
    //cout<<obj[i]<<endl;    wrong ans
//}


    return 0;
}