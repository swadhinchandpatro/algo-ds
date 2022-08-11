#include <bits/stdc++.h>
using namespace std;

void binaryInsert(vector<int> &v, int num, int start, int end) {
  if(start <= end) {
    if(num <= v[start]) {
      v.insert(v.begin()+ start, num);
      return;
    }
    if(num >= v[end]) {
      v.insert(v.begin() + end + 1, num);
      return;
    }

    int mid = floor((start + end)/2);
    if(num < v[mid]) {
      binaryInsert(v, num, start, mid);
    } else if(num > v[mid]) {
      binaryInsert(v, num, mid+1, end);
    } else {
      v.insert(v.begin() + mid, num);
    }
  }
  
}



void print(vector<int> &v) {
  for(int i = 0; i < v.size();i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main() {
  vector<int> arr = {10, 9, 8, 7, 4, 70, 60, 50};
  int k=4;
  for(int i=1;i<arr.size();i++) {
      int num = arr[i];
      arr.erase(arr.begin() + i);
      binaryInsert(arr, num, i-k >= 0 ? i-k: 0, i-1);
  }
      print(arr);
}