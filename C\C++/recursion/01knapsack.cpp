#include<iostream>
using namespace std;

struct sack
{
    int weight;
    int profit;
};
int maxi=0;


void knap(int cap, sack s[], int pro, int i,int obj[]){
//cout<<"profit = "<<pro<<endl;
if(cap>=0){
    if(maxi<pro){
    maxi = pro;
     obj[i-1] = s[i-1].weight;
    }
    
}
if((cap<=0)||(i==4))
return;


if(cap-s[i].weight>=0)
knap(cap-s[i].weight,s,pro+s[i].profit,i+1,obj);

knap(cap,s,pro,i+1,obj);

}



int main(){
 int knapsack_cap=40,obj[4];
 sack s[4];
 s[0].weight = 25;
 s[0].profit = 40;
 s[1].weight = 15;
 s[1].profit = 30;
 s[2].weight = 10;
 s[2].profit = 15;
 s[3].weight = 30;
 s[3].profit = 65;

knap(knapsack_cap,s,0,0,obj);
cout<<"Maximum profit : "<<maxi<<endl;
cout<<"object included are of weight : "<<endl;
for (int i = 0; i < 4; i++)
{   if(obj[i]!=0)
    cout<<obj[i]<<endl;  
}


    return 0;
}