// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> i, vector<vector<int>> &v, int minIndex) {
    return v[(minIndex+1)%3][i[(minIndex+1)%3]] > v[(minIndex+2)%3][i[(minIndex+2)%3]] ? (minIndex+1)%3 : (minIndex+2)%3;
}

int getMin(vector<int> i, vector<vector<int>> &v) {
    if(v[0][i[0]] < v[1][i[1]] && v[0][i[0]] < v[2][i[2]])
        return 0;
    if(v[1][i[1]] < v[0][i[0]] && v[1][i[1]] < v[2][i[2]])
        return 1;
    return 2;
}

int getMinDiff(vector<vector<int>> &v) {
    vector<int> p = {0,0,0};
    int minDiff = INT_MAX;
    int minIndex = 0, maxIndex;
    while(p[minIndex] < v[minIndex].size()) {
      //find min
      minIndex = getMin(p, v);
      maxIndex = getMax(p, v, minIndex);
    //   cout<<<<"l "<<v[maxIndex][p[maxIndex]]<<" ";
      //find diff and update min diff
      int diff = v[maxIndex][p[maxIndex]] - v[minIndex][p[minIndex]];
      if(diff < minDiff) {
        minDiff = diff;
      }
      //increment min indice
      p[minIndex]++;
    }
    
    return minDiff;
}

int main() {
    // Write C++ code here
    vector<vector<int>> v = {  {1, 4, 5, 8,12},
                        {9 , 13},
                        {2, 3, 6, 6,14} };
    
    cout<<getMinDiff(v);
    
    return 0;
}