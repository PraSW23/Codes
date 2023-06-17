#include <string>
#include <vector>
#include <iostream>
using namespace std;
int integers[3];

void parseInts(string str) {
	// Complete this function
   // vector<int> ans;
  for(int i=0,j=0;i<str.length();i++){
      
      if((str[i]==',')||(i==str.length()-1)){
        integers[j++] = stoi(str.substr(0,i+1));
        str = str.substr(i+1);
         i=0;
      }
  }
     //return ans;
}

int main() {
    string str;
    cin >> str;
   parseInts(str);
    for(long unsigned int i = 0; i < 3; i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}