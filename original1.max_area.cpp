// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &v) {
    vector<int> p;
    p.push_back(0);
    p.push_back(v.size()-1);
    int maxArea = INT_MIN;
    while(p[0] < p[1]) {
        int min = v[p[0]] < v[p[1]] ? 0 : 1;
        int area = v[p[min]] * (p[1] - p[0]);
        if(area > maxArea) {
            maxArea = area;
        }
        p[min] = min == 0 ? p[min] + 1: p[min] - 1;
    }
    return maxArea;
}

int main() {
    // Write C++ code here
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    
    cout<<getMaxArea(v);
    
    return 0;
}