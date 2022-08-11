#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
  for(auto i=v.begin(); i!=v.end(); i++) {
    cout<<*i<<" ";
  }
}

void arrange(vector<int> &v) {
  int l=-1,r=v.size();
  int i=0;
  while(v[l+1] == 0) {
      l++;
  }
  while(v[r-1] == 2) {
      r--;
  }
  while(l<r && i<r) {
    if(v[i] == 2) {
      swap(v[i],v[r-1]);
      r--;
    }
    if(v[i] == 0) {
      swap(v[i],v[l+1]);
      l++;
    }
    i++;
  }
}
int main() {
    // Write C++ code here
    vector<int> v = {1,0,2,2,0,0,1,1,1,0};
    
    arrange(v);
    print(v);
    return 0;
}