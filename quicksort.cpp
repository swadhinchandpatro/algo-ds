// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
    for(int i=0;i<v.size();i++){
        cout<<v[i]<< " ";
    }
}

void quickSort(vector<int> &v, int start, int end) {
    if(start < end) {
        int n = end -start + 1;
        int i=0,j= end;
        int pivot = v[end];
        while(i<j) {
            while(i < j && v[i] <= pivot) {
                i++;
            }
            while(i < j && v[j] >= pivot) {
                j--;
            }
            if(i < j) {
                swap(v[i], v[j]);
            }
            print(v);
            cout<<endl;
        }
        swap(v[i], v[end]);
        quickSort(v, start, i-1);
        quickSort(v, i+1, end);
    }
}
int main() {
    
    vector<int> arr = {4,6,2,34,56,22,1,54,1,4};
    quickSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}