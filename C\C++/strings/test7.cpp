#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t,i,n,k,max=0,count=1;
	char ch;
	
	cin>>t;
	while(t--){
	    string s,s2,s1;
	    cin>>n;
	    cin>>s;
	    max = 0;
	    ch = s[0];
	    for(i=1;i<s.size();i++){
	        s1 = s;
	        if(s[i]==ch){
	            count++;
	            if(max<count-1)
	            max = count-1;
	        }else {
	            s2 = s.substr(i-1,count);
                cout<<"s2 = "<<s2<<endl;
                 s1.erase(i-count-1,count);
                 k = s1.find(s2);
	            if((k<n)&&(k>-1)){ 
	                if(max<s2.length())
	                max = s2.length();
                    cout<<"maxi = "<<max<<endl;
	            }
	            count =1;
	            ch = s[i];

	        }
	    }
	    cout<<max<<endl;
	}
	
	
	return 0;
}
