#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v, int start, int end) {
    for(int i=start;i<end;i++){
        cout<<i<< " ";
    }
}

void findLargestSequence(vector<int> bits, int m) {

  int start = 0, end = 0;
  int n = bits.size();
  int max = INT_MIN;
  int ansStart = 0;
  if(m == 0) {
    if(bits[0] == 0) { start = -1;}
    while(start < n && end < n) {
      if(bits[end] == 1 && start == -1) {
        start = end;
      }
      else if(bits[end] == 0 && start != -1) {
        if(end - start > max) {
          max = end - start;
          ansStart = start;
        }
        start = -1;
      }
        end++;
    }
  }
  while(start < n && end < n) {
    
    while((m > 0 && end < n) || bits[end] == 1) {
      if(bits[end] == 0) { m--; }
      end++;
    }
    if(end - start > max) {
      max = end - start;
      ansStart = start;
    }
    if(bits[start] == 0) {
      m++;
    }
    start++;
  }
  print(bits, ansStart, ansStart + max);
}

int main() {
  vector<int> bits = {1, 1, 0,1,1,0,0,1,1,1};
  int m = 3;

  findLargestSequence(bits, m);

  return 0;
}