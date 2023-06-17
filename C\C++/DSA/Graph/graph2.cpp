 #include<iostream>
 #include<vector>

using namespace std;

int main(){

 int N,M,p,q,i,j,w;

    cout<<"Enter the no of vertices and Edges : ";
    cin>>N>>M;

    vector< pair<int,int> >g[N];


    cout<<"Enter edges with weight: ";

    for ( i = 0; i < M; i++)
    {
        cin>>p>>q>>w;
        g[p-1].push_back({q,w});
        g[q-1].push_back({p,w});
        
    }
    

    for ( i = 0; i < N; i++)
    {  // cout<<"i = "<<i;
        for ( j = 0; j < g[i].size(); j++)
        {
            cout<<i+1<<"--"<<g[i][j].first<<"  weight = "<<g[i][j].second<<endl;
        }
        
    }
    
  cout<<"Enter the edge to find weight : ";
  cin>>p>>q;

  for(pair<int,int>k: g[p-1]){

    if(k.first==q){
        cout<<"weight is : "<<k.second<<endl;
        break;
    }
    
  }


//   int x[5] = {1,2,3,4,5};

//   for(int i : x){
//     cout<<"x = "<<i<<endl;
//   }



return 0;
}